#!/bin/sh

nasm -fbin bootloader.s -o loader.bin
qemu-img create boot.img 2M
echo -e "n\np\n1\n\n\nw" | fdisk ./boot.img
fdisk -l ./boot.img
dd if=./loader.bin of=./boot.img conv=notrunc
qemu-system-x86_64 -drive format=raw,file=boot.img
