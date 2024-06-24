section .data
    nl db "", 10
    nllen equ $-nl

    show db 'Fibonacci series: 0 '
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

; NEWLINE MACRO
%macro endl 0
    mov eax, 4
    mov ebx, 1
    mov ecx, nl
    mov edx, nllen
    int 80h
%endmacro

%macro fibo 3
    mov al, [%1]
    mov bl, [%2]
    sub al, '0'
    sub bl, '0'
    add al, bl
    add al, '0'
    mov [%3], al
%endmacro

section .bss
    i resb 1
    a resb 1
    b resb 1
    c resb 1

section .text
    global _start
_start:
    write show, showlen

    mov [i], byte '2'
    mov [a], byte '1' 
    mov [b], byte '1'

loop:
    fibo a, b, c
    write a, 1        
    write space, spacelen
    mov bl, [b]
    mov [a], bl
    mov bl, [c]
    mov [b], bl
    inc byte [i]

    mov al, [i]
    cmp al, '8'
    jne loop

    endl
    ; EXIT CALL
    mov eax, 1
    mov ebx, 0
    int 80h
