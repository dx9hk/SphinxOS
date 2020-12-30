/*
 * =====================================================================================
 *
 *       Filename:  framebuffer.h
 *
 *    Description:  helper functions to modify framebuffer 
 *
 *        Version:  1.0
 *        Created:  12/29/2020 06:30:22 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */

#ifndef FRAMEBUFFER_H
#define FRAMEBUFFER_H

#include "io.h"

char* framebuffer = (char *)0x000B8000;

/*

@write_cell
@param1 -> location -> location where to write
* Location is determined by (yx)
* increment y by 160 to get to the next row starting at row 0.
* x's bounaries range from 0-9
* 324 is row 2(3rd row) and indented by 4.
@param2 -> index -> index cell for framebuffer
@param3 -> character -> character to write
@param4 -> background -> background colour of text
@param5 -> text_color -> colour for text

*/

void write_cell(unsigned int index,unsigned short location, char character, unsigned char background, unsigned char text_color){
    //set framebuffer index to the char to display
    framebuffer[index + location] = character;
    //next index = foreground + background
    framebuffer[(index + location) + 1] = ((background & 0x0F) << 4 | (text_color & 0x0F));
}

/*
@write_string_cell
@param1 -> s -> string

@return -> length of param s
*/

unsigned int strlen(const char *s)
{
    unsigned int ret = 0;
    while(s[ret] != '\0'){
        ret++;
    }
    return ret;
}


/*
 
@fb_move_cursor
@param1 -> pos -> The new position of the cursor

*/

void fb_move_cursor(unsigned short pos)
{
    outb(FB_COMMAND_PORT, FB_HIGH_BYTE_COMMAND);
    outb(FB_DATA_PORT,    ((pos >> 8) & 0x00FF));
    outb(FB_COMMAND_PORT, FB_LOW_BYTE_COMMAND);
    outb(FB_DATA_PORT,    pos & 0x00FF);
}

/*

@write_string_cell
@param1 -> location -> location where to write
* Location is determined by (yx)
* increment y by 160 to get to the next row starting at row 0.
* x's bounaries range from 0-9
* 324 is row 2(3rd row) and indented by 4.
@param2 -> stringtowrite -> string to write to the buffer
@param3 -> background -> background colour of text
@param4 -> text_color -> colour for text

*/




void write_string_cell(unsigned short location, const char* stringtowrite, unsigned char background, unsigned char text_color){
    unsigned int bytes_until_newline = 1;
    for(unsigned int i = 0; i < strlen(stringtowrite); i++) {
        if(stringtowrite[i] == '\n'){
            // if newline char has been reached, increase position by size of screen - current poistion * 2 
            location += 160 - bytes_until_newline * 2;
            bytes_until_newline = 1;
        }
        else {
            bytes_until_newline++;
            write_cell(i * 2, location, stringtowrite[i], background, text_color);
        }
        
    }
    fb_move_cursor(location / 2 + strlen(stringtowrite));
}

#endif
