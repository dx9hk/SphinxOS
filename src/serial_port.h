#ifndef _SERIAL_PORT_H_
#define _SERIAL_PORT_H_

/* I/O ports */

#define SERIAL_COM1_BASE                  0x3F8 /* COM1 base port */

#define SERIAL_DATA_PORT(base)            (base)
#define SERIAL_FIFO_COMMAND_PORT(base)    (base + 2)
#define SERIAL_LINE_COMMAND_PORT(base)    (base + 3)
#define SERIAL_MODEM_COMMAND_PORT(base)   (base + 4)
#define SERIAL_LINE_STATUS_PORT(base)     (base + 5)

/* The I/O port commands */

/* Serial line enable DLAB:
 * Tells the serial port to expect first high and low 8 bits on
 * the data port
 */
#define SERIAL_LINE_ENABLE_DLAB           0x80


void serial_configure_baud_rate(unsigned short com, unsigned short divisor);

void serial_configure_line(unsigned short com);

void serial_write(char *buffer, unsigned int len);

int serial_is_transmit_fifo_empty(unsigned int com);

#endif
