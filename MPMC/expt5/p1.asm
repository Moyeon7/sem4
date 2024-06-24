sys_write equ 4
	sys_exit equ 1
	sys_read equ 3
	stdout equ 1
	stdin equ 0
section .data

	show db "7", 10
	showlen equ $-show

%macro write 2
	mov eax, sys_write
	mov ebx, stdout
	mov ecx, %1
	mov edx, %2
	int 80h
%endmacro

section .bss
	num resb 2

section .text
global _start
_start:
	write show, showlen

	mov eax,sys_exit
	mov ebx,ebx
	int 80h
