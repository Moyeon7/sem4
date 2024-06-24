sys_write equ 4
	sys_exit equ 1
	sys_read equ 3
	stdout equ 1
	stdin equ 0
section .data
	newline db "", 10
	len1 equ $-newline

	ask db "Enter a number: "
	asklen equ $-ask
	
	show db 'The entered number is '
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
	num resb 1
section .text
global _start
_start:
	
	write ask, asklen
	read num, 1
	write show, showlen
	write num, 1
	write newline, len1

	mov eax,sys_exit
	mov ebx,ebx
	int 80h
