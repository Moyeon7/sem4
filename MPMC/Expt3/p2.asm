sys_write equ 4
	sys_exit equ 1
	sys_read equ 3
	stdout equ 1
	stdin equ 0
section .data
	newline db "", 10
	len1 equ $-newline

	ask1 db "Enter 1st number: "
	asklen1 equ $-ask1
	
	ask2 db "Enter 2nd number: "
	asklen2 equ $-ask2

	sum db 'The sum is: '
	sumlen equ $-sum

	mull db 'The multiplication is: '
	mullen equ $-mull
	
	subb db 'The subtraction is: '
	subblen equ $-subb

	divv db 'The division is: '
	divlen equ $-divv

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
	num1 resb 2
	num2 resb 2
	result resb 1
	remainder resb 1

section .text
global _start
_start:
	
	write ask1, asklen1
	read num1, 2
	write ask2, asklen2
	read num2, 2
	
	write newline, len1

	mov eax, [num1]
	sub eax, '0'
	mov ebx, [num2]
	sub ebx, '0'
	add eax, ebx
	add eax, '0'
	mov [result], eax
	write sum, sumlen
	write result, 1
	write newline, len1

	mov eax, [num1]
	sub eax, '0'
	mov ebx, [num2]
	sub ebx, '0'
	sub eax, ebx
	add eax, '0'
	mov [result], eax
	write subb, subblen
	write result, 1
	write newline, len1

	mov eax, [num1]
	sub eax, '0'
	mov ebx, [num2]
	sub ebx, '0'
	mul ebx
	add eax, '0'
	mov [result], eax
	write mull, mullen
	write result, 1
	write newline, len1

	mov al, [num1]
	sub al, '0'
	mov bl, [num2]
	sub bl, '0'
	div bl
	add ah, '0'
	add al, '0'
	mov [result], al
	mov [remainder], ah
	write divv, divlen
	write result, 1
	write newline, len1

	mov eax,sys_exit
	mov ebx,ebx
	int 80h
