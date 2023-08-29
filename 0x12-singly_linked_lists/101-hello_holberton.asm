section .data
    hello db "Hello, Holberton", 0
    format db "%s", 0

section .text
    global main
    extern printf

main:
    push rdi                  ; Preserve registers if needed
    push rsi

    lea rdi, [format]         ; Load format string address
    lea rsi, [hello]          ; Load hello string address
    xor rax, rax              ; Clear RAX (no xmm registers used)
    call printf              ; Call the printf function

    pop rsi                   ; Restore registers if needed
    pop rdi

    xor eax, eax              ; Return 0
    ret

