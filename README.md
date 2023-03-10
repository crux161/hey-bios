
otloader Readme

x86\_64 Bootloader Readme
=========================

This is a simple x86\_64 bootloader that prints the message "Hello, world!" to the screen.

Usage
-----

First, compile the bootloader:

nasm -f bin bootloader.asm -o bootloader.bin

Then, create a disk image using the bootloader as the boot sector:

dd if=/dev/zero of=disk.img bs=512 count=2880
    dd if=bootloader.bin of=disk.img conv=notrunc

    Finally, run the disk image in QEMU:

    qemu-system-x86\_64 -drive file=disk.img,index=0,if=floppy,format=raw

    License
    -------

    This project is licensed under the MIT License. See LICENSE file for details.
