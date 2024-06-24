section .data
    nl db "", 10
    nllen equ $-nl

    show db 'The odd numbers from 0-9 are: '
    showlen equ $-show

    space db ' '
    spacelen equ $-space

; WRITE MACRO
%macro write 2
    mov eax, 4
    mov ebx, 1
    mov ecx, %1
    mov edx, %2
    int 80h
%endmacro

; READ MACRO
%macro read 2
    mov eax, 3
    mov ebx, 2
    mov ecx, %1
    mov edx, %2
    int 80h
%endmacro

; NEWLINE MACRO
%macro endl 0
    mov eax, 4
    mov ebx, 1
    mov ecx, nl
    mov edx, nllen
    int 80h
%endmacro

; DECLARE VARIABLES
section .bss
    num resb 1
    count resb 1

section .text
    global _start
_start:

    write show, showlen
    mov byte [count], '0'
    mov byte [num], '1'
     loop:
        inc byte [count]
        mov al, [count]
        cmp al, '6'
        je exit
        write num, 1
        write space, spacelen
        inc byte[num]
        inc byte[num]
    jmp loop

    exit:
    ; EXIT CALL
    mov eax, 1
    mov ebx, 0
    int 80h
