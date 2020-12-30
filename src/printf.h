#ifndef printf_h
#define printf_h
#include "framebuffer.h"
#include "serial_port.h"
#include "colours.h"
enum OutputType{
    oFramebuffer,
    oDriver
};


#define va_start(ap, param) __builtin_va_start(ap, param)
#define va_end(ap)          __builtin_va_end(ap)
#define va_arg(ap, type)    __builtin_va_arg(ap, type)

void krnl_printf(const char* buffer, unsigned int type, int location, unsigned int bg, unsigned int textCol){
    switch (type)
    {
    case 0:
    {
        write_string_cell(location,buffer,bg,textCol);
        break;
    }
    case 1:
    {
        serial_write(buffer);
        break;
    }
    }
}



#endif