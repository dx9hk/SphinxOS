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
#include "printf.h"
#define NULL 0


void kmain(void) {
    
    /*write_string_cell(
        1280,
        "Testing our newline character\nLooks like it works!",
        0x0,0xF);

    serial_write("Testing output, \nserial_write has been called!");
    */
   krnl_printf("Testing my os_printf",oFramebuffer,1280,Black,White);
   krnl_printf("Testing my os_printf",oDriver,NULL,NULL,NULL);
}
