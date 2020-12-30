#ifndef gdt_h
#define gdt_h

struct gdt{
  unsigned int startAddr;
  unsigned int size;
}__attribute__((packed));


#endif