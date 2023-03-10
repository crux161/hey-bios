# hey-bios Bootloader
=========================

This is a simple x86\_64 bootloader that prints the message "Hello, world!" to the screen.

## Prerequisites

- NASM
- QEMU

## Compiling and Running

To compile and run the bootloader, follow these steps:

    Clone this repository:

	git clone https://github.com/crux161/hey-bios.git
	cd hey-bios

    Compile the bootloader:
	nasm -f bin bootloader.s -o loader.bin

    or run:
	./build.sh

    Prepare the disk image for qemu:
    	qemu-img create boot.img 2M
	fdisk ./boot.img  # you need to make a new primary partition and write that to the disk image before exiting.
	fdisk -l boot.img # this should show a primary partition having been created, a necessary step to proceed.
	dd if=./loader.bin of=./boot.img conv=notrunc

    Run the bootloader:
	qemu-system-x86_64 -drive format=raw,file=boot.img
	

If successful, you should see "Hello world!" printed to the screen.


## License

This project is licensed under the MIT License. See LICENSE file for details.
