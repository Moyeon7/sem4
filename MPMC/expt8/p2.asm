section .data 
msg1 db 'Positive numbers: '  
msg1len equ $-msg1 
msg2 db 'Negative numbers: '  
msg2len equ $-msg2 
new db '',10 
nl equ $-new 
arr db 1, 2, -3, -4, 5 

%macro write 2 
mov eax,4 
mov ebx,1 
mov ecx, %1 
mov edx, %2 
int 80h 
%endmacro 

%macro read 2 
mov eax,3 
mov ebx,2 
mov ecx,%1 
mov edx,%2 
int 80h 
%endmacro
 
count: 
mov eax, 0 
mov [pcnt],eax 
mov [ncnt], eax 
mov ecx, 5 
mov esi, 0 
mov edx,arr 

label: 
mov bl, [esi+edx]  
cmp bl,0 
jg positive 
inc byte[ncnt] 
jmp end 

positive: 
inc byte[pcnt] 

end: 
inc esi 
loop label 
mov eax, [pcnt] 
add eax, '0' 
mov [pcnt], eax 
mov eax, [ncnt] 
add eax, '0' 
mov [ncnt], eax 
ret 

section .bss 
pcnt resb 1 
ncnt resb 1 

section .text 
global _start 
_start: 

call count 
write msg1,msg1len 
write pcnt, 1 
write new,nl 
write msg2,msg2len 
write ncnt, 1 
write new,nl
 
mov eax ,1 
mov ebx ,0 
int 80h 