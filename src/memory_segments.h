#ifndef _MEMORY_SEGMENTS
#define _MEMORY_SEGMENTS

typedef struct gdt
{
  unsigned int address;
  unsigned short size;
}__attribute__((packed)) gdt;

void lgdt_func(gdt GDT);

#endif
