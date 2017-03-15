g = -9.81;    %Gravitational acceleration (m/s2)
B = 0;         %Incline angle (rad)
m = 81;         %Vehicle mass (kg)
A = 3.56;         %Effective frontal vehicle cross-sectional area (m2)
h = 0.1524;         %Height of vehicle CG above the ground (m)
a = 0.6;          %Distance of front and rear axles, respectively, from the vertical projection point of vehicle CG onto the axle-ground plane (m)
b = 0.6;         %Distance of front and rear axles, respectively, from the vertical projection point of vehicle CG onto the axle-ground plane (m)

Vx =         %Longitudinal vehicle velocity (m/s)
Fxf =        %Longitudinal forces on the vehicle at the front and rear wheel ground contact points, respectively (N)
Fxr =        %Longitudinal forces on the vehicle at the front and rear wheel ground contact points, respectively (N)
Fzf =        %Vertical load forces on the vehicle at the front and rear ground contact points, respectively (N)
Fzr =        %Vertical load forces on the vehicle at the front and rear ground contact points, respectively (N)

Cd = 0.076;         %Aerodynamic drag coefficient (N�s2/kg�m)
p = 1.2;      %Mass density of air (kg/m3)

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%   The vehicle motion is determined by the net effect of all the forces and torques acting on it. 
%   The longitudinal tire forces push the vehicle forward or backward. The weight mg of the vehicle 
%   acts through its center of gravity (CG). Depending on the incline angle, the weight pulls the 
%   vehicle to the ground and either pulls it backward or forward. Whether the vehicle travels forward or backward, 
%   aerodynamic drag slows it down. For simplicity, the drag is assumed to act through the CG.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

Fd = 0.5*Cd*p*A*(Vx^2); %Aerodynamic drag force (N)
m*Vx = (Fx+Fd)-(mg*sin(B)); 
Fx = Fxf + Fxr;
Fd= -12Cd?AVx2?sgn(Vx)

%Zero vertical acceleration and zero pitch torque require
Fzf = (+h(Fd?mgsin??m?Vx)+b?mgcos?)/(a+b)
Fzr = (-h(Fd?mgsin??m?Vx)+b?mgcos?)/(a+b)
%Note that Fzf + Fzr = mg�cos?

