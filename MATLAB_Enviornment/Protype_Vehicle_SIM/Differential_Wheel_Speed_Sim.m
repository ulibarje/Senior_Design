%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%                                           %
%	Live Matlab Plotting Via Serial         %
%   Variable length data logging            %
%   float inputs only                       %
%	Serial Port: COM1-7 (User defined)      %
%                                           %
%	Serial Setting, Graph Settings,         %
%   Log Settings, etc. are all user defined.%
%                                           %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%Clear workplace and variable before run
clear;
clc;

try
    %Select the total number of floats, (num_of_in_float), 
    %being sent via serial every cycle; and which speed 
    %you would like to sample for input.
    serialPort = 'COM4';                %Define COM port #
    baudrate = 76800;                   %Define baudrate of data
    num_of_in_float = 4;                %Define # of Float/packet
    delay = 0.01;                      %Make sure sample faster than resolution

    %Log file name and column titles 
    Log_Title = 'DataLog.txt';
    fileID = fopen(Log_Title,'w');
    fprintf(fileID,'%s,%s,%s,%s,%s,%s,%s\r\n','Time(s)','Target Torque','Torque Output Left','Torque Output Right','Steering Angle (Binary)');

    %Other User Defined Properties
    plotTitle = 'Steering Wheel Angle';   %Plot title
    xLabel = 'Elapsed Time(s)';         %X-axis label
    yLabel = 'Steering Angle (Degree)';        %Y-axis label
    plotGrid = 'on';                    %'off' to turn off grid
    scrollWidth = 20;                   %Display period in plot, plot entire data log if <= 0

    %Choose which input float to graph (float_to_graph,then
    %indicate the maximum and minimum value that it can be.
    float_to_graph = 1;                 %Define which float to graph     
    min = 0;                            %Define y-min
    max = 20;                           %Define y-max

    %Define Function Variables
    time = 0;
    data = 0;
    count = 0;
    num_of_bytes = (num_of_in_float*4);

    %Set up Plot
    plotGraph = plot(time,data,'-mo','LineWidth',1,'MarkerEdgeColor','k','MarkerFaceColor',[.49 1 .63],'MarkerSize',2);

    %Set plot grid, title, and axis lables
    title(plotTitle,'FontSize',25);
    xlabel(xLabel,'FontSize',15);
    ylabel(yLabel,'FontSize',15);
    axis([0 10 min max]);

    %Append grid to plot at users command
    grid(plotGrid);

    %Generate plot and pause slightly to let it open
    disp('Close Plot to End Session');
    pause(delay);

    %Create and Configure Serial COM Port with user settings
    s = serial(serialPort);
    s.InputBufferSize = num_of_bytes;
    set(s,'Terminator','LF');
    set(s,'BaudRate', baudrate);
    set(s,'DataBits', 8);
    set(s,'Parity','none');
    set(s,'StopBits', 1);
    set(s,'FlowControl','none');
    set(s,'InputBufferSize', num_of_bytes);
    set(s,'BytesAvailableFcnCount', num_of_bytes);
    set(s,'BytesAvailableFcnMode','byte');

    %Open the Serial Com Port and allow to open (pause)
    fopen(s);
    pause(1);

    %Set the internal timer at the execution of the 'tic' command. 
    %This timer's value can be accessed as by a subsequent call to 'toc'. 
    tic

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%   User Settings: Configures the simulation, read below for info
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%



%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    
    %Loop when Plot is Active 
    while ishandle(plotGraph)
        CheckPacket = fread(s, 1, 'char');
        %Make sure incoming data contains the correct "set current command 'S'."
        if(CheckPacket == 'S')
            CheckPacket = 0;       

            Rx_data_packet = fread(s, num_of_in_float, 'float32')        
            %Read data off the serial bus as 32-bit floats.      
            Base_Torque = Rx_data_packet(0)            
            Set_Torque_Right = Rx_data_packet(1)            
            Set_Torque_Left =  Rx_data_packet(2)
            Steering_Angle_Bin = Rx_data_packet(3)
            
            if(~isempty(Rx_data_packet) && isfloat(Rx_data_packet))  
            %Make sure read data is a Float and not an empty array      

                %Plot some given data
                count = count + 1;    
                time(count) = toc;                                   
                %Extract Elapsed Time

                %Extract user selected data to graph
                data(count) = Rx_data_packet(float_to_graph);

                %Adjust the graph's X-axis according to 'Scroll Width'.
                %It is adjusted using the current 'time' and 'count'. 
                if(scrollWidth > 0)
                    set(plotGraph,'XData',time(time > time(count)-scrollWidth),'YData',data(time > time(count)-scrollWidth));
                    axis([time(count)-scrollWidth time(count) min max]);                
                %Plot the given float without adjusting for 'Scroll Width'
                else
                    set(plotGraph,'XData',time,'YData',data);
                    axis([0 time(count) min max]);
                end
            end

           
            
%Left turn (0 to -180 Degrees) = (4085 - 2048)            
%Left Turn vs Torque Multiplier
Steering_Angle_Deg = (Steering_Angle_Bin*11.3778)-360
LTR = 1.033849*ln(Steering_Angle_Bin) - 7.588172;
Target_Torque_Left = Set_Torque_Left*LTR
Target_Torque_Right = Set_Torque_Right 

%Right turn (0 to +180 Degrees) = (0 to 2048)
%Right Turn vs Torque Multiplier
Steering_Angle_Deg = Steering_Angle_Bin*11.3778
RTR = -8E-08*(Steering_Angle)^2 - 0.0002*(Steering_Angle) + 0.9863;             
Target_Torque_Left = Set_Torque_Left
Target_Torque_Right = Set_Torque_Right*RTR         
            
            %Save all input floats to the log file,
            %first with the current time, followed
            %by all of the read floats, ending with
            %a new-line. Log is CSV compatable.
            fprintf(fileID,'%f,',toc);
            for i = 1:num_of_in_float
                fprintf(fileID,'%f,',Rx_data_packet(i));  
            end
            fprintf(fileID,'\r\n');

            %Allow MATLAB time to Update Plot
            pause(delay);
        end
    Rx_data_packet = 0;
    end

catch ME
   fprintf(1, 'An error occured, please ensure all user defined variables are set correctly\r\n'); 
   fprintf(1, 'ERROR MESSAGE:\n%s\n\n', ME.message); 
end    

%Close Serial COM Port and Delete useless Variables
fclose(s);
%Close log file
fclose(fileID);
%Clear out all of the used variables and terminate the script.
clear count Rx_data_packet delay max min plotGraph plotGrid plotTitle ...
       scrollWidth serialPort xLabel yLabel A ans data fileID s time;

disp('Log/Graph Script Terminated...');
disp('Thank you for choosing EriLog for your scripting needs!');