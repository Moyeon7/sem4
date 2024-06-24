sys_write equ 4
	sys_exit equ 1
	sys_read equ 3
	stdout equ 1
	stdin equ 0
section .data

	show1 db "7", 10
	showlen1 equ $-show1
	
	show2 db "4", 10
	showlen2 equ $-show2

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
	write show1, showlen1
	write show2, showlen2

	mov eax,sys_exit
	mov ebx,ebx
	int 80h
