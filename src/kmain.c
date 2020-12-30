/*
 * =====================================================================================
 *
 *       Filename:  kmain.c
 *
 *    Description:  SphinxOS Kernel 
 *
 *        Version:  1.0
 *        Created:  12/28/2020 08:20:53 PM
 *       Revision:  none
 *       Compiler:  clang
 *
 *        Authors:  dx9hk
 *   Organization:  CoI 
 *
 * =====================================================================================
 */

#include "framebuffer.h"
#include "colours.h"
#include "serial_port.h"

void kmain(void) {
    write_string_cell(
        1280,
        "Testing our newline character\nlooks like it works!\nthis\nis\n\nscuffed",
        Black,White);

    serial_write("Testing",7);

}
