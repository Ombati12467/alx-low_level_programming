section .data
    format db "Hello, Holberton", 0

section .text
    global main
    extern printf

main:
    mov edi, format         ; Load format string address
    xor eax, eax            ; Clear RAX (no xmm registers used)
    call printf            ; Call the printf function

    xor eax, eax            ; Return 0
    ret

section .data
    format db "Hello, Holberton\n", 0
