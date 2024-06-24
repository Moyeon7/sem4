sys_write equ 4
	sys_exit equ 1
	sys_read equ 3
	stdout equ 1
	stdin equ 0
section .data
	newline db "", 10
	len1 equ $-newline
	
	space db " & "
	spacelen equ $-space

	ask1 db "Enter 1st number: "
	asklen1 equ $-ask1
	
	ask2 db "Enter 2nd number: "
	asklen2 equ $-ask2

	show db 'The two numbers are: '
	showlen equ $-show

%macro write 2
	mov eax, sys_write
	mov ebx, stdout
	mov ecx, %1
	mov edx, %2
	int 80h
%endmacro
%macro read 2
	mov eax, sys_read
	mov ebx, stdin
	mov ecx, %1
	mov edx, %2
	int 80h
%endmacro

section .bss
	num1 resb 1
	num2 resb 1
section .text
global _start
_start:
	
	write ask1, asklen1
	read num1, 2
	write ask2, asklen2
	read num2, 2
	write show, showlen
	write num1, 1
    write space, spacelen
	write num2, 1
	write newline, len1

	mov eax,sys_exit
	mov ebx,ebx
	int 80h
