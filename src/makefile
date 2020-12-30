    OBJECTS = loader.o kmain.o serial_port.o
    CC = gcc
    CFLAGS = -m32 -nostdlib -nostdinc -fno-builtin -fno-stack-protector \
             -nostartfiles -nodefaultlibs -Wall -Wextra -Werror -c
    LDFLAGS = -T link.ld -melf_i386
    AS = nasm
    ASFLAGS = -f elf

    all: kernel.elf

    kernel.elf: $(OBJECTS)
	        ld $(LDFLAGS) $(OBJECTS) -o kernel.elf

    sphinx.iso: kernel.elf
	    cp kernel.elf ../build/iso/boot/kernel.elf
	    genisoimage -R					     \
			-b boot/grub/stage2_eltorito       \
			-no-emul-boot				     \
			-boot-load-size 4			     \
			-A sphinx					     \
			-input-charset utf8                          \
			-quiet					     \
			-boot-info-table		             \
			-o sphinx.iso 				     \
			../build/iso

    run: sphinx.iso
	 qemu-system-i386                                           \
		    -accel tcg,thread=single                        \
		    -cpu core2duo                                   \
		    -m 128                                          \
		    -no-reboot                                      \
		    -drive format=raw,media=cdrom,file=sphinx.iso      \
		    -serial stdio                                   \
		    -smp 1                                          \
		    -usb                                            \
		    -vga std

    %.o: %.c
	 $(CC) $(CFLAGS)  $< -o $@

    %.o: %.s
	 $(AS) $(ASFLAGS) $< -o $@

    clean:
	rm -rf *.o kernel.elf sphinx.iso
