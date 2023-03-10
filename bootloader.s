section .text
    global _start

_start:
    ; Set video mode
    mov ah, 0x00
    mov al, 0x03
    int 0x10

    ; Set cursor position
    mov ah, 0x02
    mov bh, 0x00
    mov dh, 0x00
    mov dl, 0x0a ; column 10
    int 0x10

    ; Print message
    mov ah, 0x0e ; print char function
    mov al, 'H'
    int 0x10
    mov al, 'e'
    int 0x10
    mov al, 'l'
    int 0x10
    mov al, 'l'
    int 0x10
    mov al, 'o'
    int 0x10
    mov al, ' '
    int 0x10
    mov al, 'w'
    int 0x10
    mov al, 'o'
    int 0x10
    mov al, 'r'
    int 0x10
    mov al, 'l'
    int 0x10
    mov al, 'd'
    int 0x10
    mov al, ' '
    int 0x10
    mov al, 'f'
    int 0x10
    mov al, 'r'
    int 0x10
    mov al, 'o'
    int 0x10
    mov al, 'm'
    int 0x10
    mov al, ' '
    int 0x10
    mov al, 'c'
    int 0x10
    mov al, 'r'
    int 0x10
    mov al, 'u'
    int 0x10
    mov al, 'x'
    int 0x10

    ; Infinite loop
    cli
    hlt
    jmp $

