#include "io.h"
#include "serial_port.h"



/* Sets the speed of the serial port, default speed fot port is 
 * 11520 bits. 
 * 
 * How the Contents of byte on the line command port:
 *    Bit:     | 7 | 6 | 5 4 3 | 2 | 1 0 |
 *    Content: | d | b | prty  | s | dl  |
 *
 * @param com is the given COM to configure
 * @param divisor to help set the speed
 */
void serial_configure_baud_rate(unsigned short com, unsigned short divisor) {
    outb(SERIAL_LINE_COMMAND_PORT(com), SERIAL_LINE_ENABLE_DLAB);
    outb(SERIAL_DATA_PORT(com), (divisor >> 8) & 0x00FF);
    outb(SERIAL_DATA_PORT(com), divisor & 0x00FF);
}


/* Configure the line of the serial port. We'll be using the standard
 * value, 0x03, a data length of 8 bits, no parity bits, one stop bit
 * and break control disabled.
 *
 * Bit:     | 7 | 6 | 5 4 3 | 2 | 1 0 |
 * Content: | d | b | prty  | s | dl  |
 * Value:   | 0 | 0 | 0 0 0 | 0 | 1 1 | = 0x03
 *
 * */
void serial_configure_line(unsigned short com) {
    outb(SERIAL_LINE_COMMAND_PORT(com), 0x03);
}

/* Checks whether the FIFO queue is empty or not from a given com port.
 *
 * @param com the COM port
 * @returns 0 if transmit FIFO queue is empty or returns 1 if not empty.
 * 
 * 0x20 = 0010 0000
 *
 * */
int serial_is_transmit_fifo_empty(unsigned int com) {
    return inb(SERIAL_LINE_STATUS_PORT(com)) & 0x20;
}


/* Initiate The serial 
int initiate_serial() {
    outb(SERIAL_COM1_BASE + 1, 0x00);    // Disable all interrupts
    outb(SERIAL_COM1_BASE + 3, 0x80);    // Enable DLAB (set baud rate divisor)
    outb(SERIAL_COM1_BASE + 0, 0x03);    // Set divisor to 3 (lo byte) 38400 baud
    outb(SERIAL_COM1_BASE + 1, 0x00);    //                  (hi byte)
    outb(SERIAL_COM1_BASE + 3, 0x03);    // 8 bits, no parity, one stop bit
    outb(SERIAL_COM1_BASE + 2, 0xC7);    // Enable FIFO, clear them, with 14-byte threshold
    outb(SERIAL_COM1_BASE + 4, 0x0B);    // IRQs enabled, RTS/DSR set
    outb(SERIAL_COM1_BASE + 4, 0x1E);    // Set in loopback mode, test the serial chip
    outb(SERIAL_COM1_BASE + 0, 0xAE);    // Test serial chip (send byte 0xAE and check if serial returns same byte)

    

}
*/


void serial_write(char *buffer, unsigned int len) {
  serial_configure_baud_rate(SERIAL_COM1_BASE, 0x03);
  serial_configure_line(SERIAL_COM1_BASE);

  unsigned int i = 0;
  for(; i < len; i++) {
    while (!serial_is_transmit_fifo_empty(SERIAL_COM1_BASE))
    outb(SERIAL_DATA_PORT(SERIAL_COM1_BASE), buffer[i]);
  }
}
