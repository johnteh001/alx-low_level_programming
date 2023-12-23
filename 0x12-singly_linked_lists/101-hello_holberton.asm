section .data
    hello_message db "Hello, Holberton", 0

section .text
    global main
    extern printf

main:
    ; Prepare arguments and call printf
    lea rdi, [hello_message]  ; Load address of hello_message into rdi
    call printf

    ; Exit the program
    mov rax, 60         ; syscall: exit
    xor rdi, rdi        ; status: 0
    syscall

section .note.GNU-stack
