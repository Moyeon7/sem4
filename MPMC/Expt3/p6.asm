section .data
	nl db "", 10
	nllen equ $-nl

	ask1 db 'Enter radius: '
	ask1len equ $-ask1

	showa db 'Area of circle: '
	showalen equ $-showa

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
	rl resb 9
	rb resb 9
	rarea resb 9

section .text
	global _start
_start:

	; GET CIRCLE
	write ask1, ask1len
	read rl, 9

	; CIRCLE AREA
	mov eax, [rl]
	mov ebx, [rl]
	sub eax, '0'
	sub ebx, '0'
	mul ebx
	mov ebx, 3
	mul ebx
	add eax, '0'
	mov [rarea], al

	; PRINT RECTANGLE
	write showa, showalen
	write rarea, 9
	endl

	; EXIT CALL
	mov eax, 1
	mov ebx, 0
	int 80h
