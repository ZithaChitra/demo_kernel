ASM=nasm

SRC_DIR=src
BUILD_DIR=build


.PHONY: all floppy_image kernel bootloader clean always


all: floppy_image 

run: all
	qemu-system-x86_64 -drive format=raw,media=disk,file=$(BUILD_DIR)/os_image.bin 

floppy_image: $(BUILD_DIR)/os_image.bin
kernel		: $(BUILD_DIR)/kernel.bin
bootloader	: $(BUILD_DIR)/boot_sector.bin


$(BUILD_DIR)/os_image.bin: $(BUILD_DIR)/boot_sector.bin $(BUILD_DIR)/kernel.bin
	cat $^ > $@
	truncate $@ -s 10240
	dd if=/dev/zero of=os_image.img count=1440
	dd if=$@ of=os_image.img seek=0 count=1 conv=notrunc


# Build the kernel binary
$(BUILD_DIR)/kernel.bin: $(BUILD_DIR)/kernel.o
	ld -o $@ -Ttext 0x7e00 $< -m elf_i386 --oformat binary

# Build the kernel object file
$(BUILD_DIR)/kernel.o:
	gcc -ffreestanding -fno-pie -c kernel/kernel_entry.c -o $@ -m32

$(BUILD_DIR)/boot_sector.bin: 
	$(ASM) boot/boot_sector.asm -f bin -o $@


always:
	mkdir -p $(BUILD_DIR)

clean:
	rm -fr $(BUILD_DIR)/*.o $(BUILD_DIR)/*.bin $(BUILD_DIR)/*.img *.img

