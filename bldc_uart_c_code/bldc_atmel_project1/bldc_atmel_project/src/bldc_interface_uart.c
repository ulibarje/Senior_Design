#include "bldc_interface_uart.h"
#include "bldc_interface.h"

// Settings
#define PACKET_HANDLER			0

// Private functions
static void process_packet(unsigned char *data, unsigned int len);
static void send_packet_bldc_interface(unsigned char *data, unsigned int len);

/**
 * Initialize the UART BLDC interface and provide a function to be used for
 * sending packets.
 *
 * @param func
 * Function provided for sending packets.
 */
void bldc_interface_uart_init(void(*func)(unsigned char *data, unsigned int len)) {
	// Initialize packet handler
	packet_init(func, process_packet, PACKET_HANDLER);

	// Initialize the bldc interface and provide a send function
	bldc_interface_init(send_packet_bldc_interface);
}

/**
 * Process one byte received on the UART. Once a full packet is received the
 * corresponding callback will be called by bldc_interface.
 *
 * @param b
 * The byte received on the UART to process.
 */
void bldc_interface_uart_process_byte(unsigned char b) {
	packet_process_byte(b, PACKET_HANDLER);
}

/**
 * Call this function at around 1 khz to reset the state of the packet
 * interface after a timeout in case data is lost.
 */
void bldc_interface_uart_run_timer(void) {
	packet_timerfunc();
}

/**
 * Callback for the packet handled for when a whole packet is received,
 * assembled and checked.
 *
 * @param data
 * Data array pointer
 * @param len
 * Data array length
 */
static void process_packet(unsigned char *data, unsigned int len) {
	// Let bldc_interface process the packet.
	bldc_interface_process_packet(data, len);
}

/**
 * Callback that bldc_interface uses to send packets.
 *
 * @param data
 * Data array pointer
 * @param len
 * Data array length
 */
static void send_packet_bldc_interface(unsigned char *data, unsigned int len) {
	// Pass the packet to the packet handler to add checksum, length, start and stop bytes.
	packet_send_packet(data, len, PACKET_HANDLER);
}


