section .data
ask1 db 'Enter number of elements: '
asklen1 equ $-ask1
ask2 db 'Enter array element: '
asklen2 equ $-ask2
say1 db 'Even numbers: '
saylen1 equ $-say1
say2 db 'Odd numbers: '
saylen2 equ $-say2
newline db "", 10
nlen equ $-newline
%macro write 2
mov eax, 4
mov ebx, 1
mov ecx, %1
mov edx, %2
int 80h
%endmacro
%macro read 2
mov eax, 3
mov ebx, 2
mov ecx, %1
mov edx, %2
int 80h
mov eax, 3
mov ebx, 2
mov ecx, tmp
mov edx, 1
int 80h
%endmacro
input:
    mov byte[a], 0
    mov esi, array
    linput:
        read ele, 1
        mov ebx, [ele]
        sub ebx, '0'
        mov [esi], ebx
        inc esi
        inc byte[a]
        mov al, [a]
        mov bl, [num]
        cmp al, bl
        jl linput
    ret
count:
    mov byte[nodd], 0
    mov byte[neven], 0
    mov esi, 0
    mov ecx, 4
    label:
        movzx edi, byte[array+esi]
        mov [tmp], edi
        mov al, [tmp]
        mov bl, 2
        div bl
        cmp ah, 0
        je loop1
        inc byte[nodd]
        jmp end
        loop1:
            inc byte[neven]
        end:
            inc esi
            loop label
            mov eax, [nodd]
            add eax, '0'
            mov [nodd], eax
            mov eax, [neven]
            add eax, '0'
            mov [neven], eax
    ret

section .bss
nodd resb 1
neven resb 1
tmp resb 5
ele resb 1
num resb 1
array resb 20
a resb 1

section .text 
global _start
_start:
    write ask1, asklen1
    read num, 1
    mov eax, [num]
    sub eax, '0'
    mov [num], eax
    write ask2, asklen2
    call input
    call count
    write say1, saylen1
    write neven, 1
    write newline, nlen
    write say2, saylen2
    write nodd, 1
    write newline, nlen
    mov eax, 1
    mov ebx, 0
    int 80h