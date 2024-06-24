section .data
    nl db "", 10
    nllen equ $-nl

    string1 db 'Morning'
    stringlen1 equ $-string1

    string2 db 'Night'
    stringlen2 equ $-string2
    
    equal db "Two strings are equal."
    equallen equ $-equal

    notequal db "No, two strings are not equal."
    notequallen equ $-notequal

section .text
global _start

_start:
    ; Compare the lengths of the strings
    mov eax, stringlen1
    cmp eax, stringlen2
    jne strings_not_equal

    ; Compare the strings character by character
    mov ecx, stringlen1
    mov esi, string1
    mov edi, string2
compare_loop:
    mov al, [esi]
    mov bl, [edi]
    cmp al, bl
    jne strings_not_equal
    inc esi
    inc edi
    loop compare_loop

    ; If we reach here, strings are equal
    mov eax, 4
    mov ebx, 1
    mov ecx, equal
    mov edx, equallen
    int 80h
    jmp exit

strings_not_equal:
    ; Strings are not equal
    mov eax, 4
    mov ebx, 1
    mov ecx, notequal
    mov edx, notequallen
    int 80h

exit:
    ; Exit the program
    mov eax, 1
    xor ebx, ebx
    int 80h
