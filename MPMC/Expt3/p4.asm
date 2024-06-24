section .data
    nl db "", 10
    nllen equ $-nl
    
    ask1 db "Enter 1st number: "
	asklen1 equ $-ask1
	
	ask2 db "Enter 2nd number: "
	asklen2 equ $-ask2

	ask3 db "Enter 3rd number: "
	asklen3 equ $-ask3

	show db 'The sum is: '
	showlen equ $-show

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
    a resb 1
    b resb 1
    c resb 1
    sum resb 1

section .text
    global _start
_start:

    write ask1, asklen1
    read a, 2
    write ask2, asklen2
    read b, 2
    write ask3, asklen3
    read c, 2
    ; ADDITION
    mov al, [a]
    mov bl, [b]
    sub al, '0'
    sub bl, '0'
    add al, bl
    mov bl, [c]
    sub bl, '0'
    add al, bl
    add al, '0'
    mov [sum], al

    write show, showlen
    write sum, 1
    endl

    ; EXIT CALL
    mov eax, 1
    mov ebx, 0
    int 80h
