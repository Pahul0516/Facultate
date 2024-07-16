bits 32

global start
extern exit 
import exit msvcrt.dll
import scanf msvcrt.dll
import printf msvcrt.dll

extern scanf
extern printf

segment data use32 class=data

    mesaj_citire db "Va rog sa introduceti un numar in baza 16: ", 0 
    format_citire db "%x", 0
    nr resb 10
    suma resb 100
    format_afisare db "Media aritmetica in baza 10 este %d", 0
    

segment code use32 class=code

start:

    mov eax, 0
    push dword mesaj_citire
    call [printf]
    add esp, 4*1
    
    push nr
    push dword format_citire
    call [scanf]
    add esp,4*2
    
    mov ebx, [nr]
    mov eax, 0
    add eax, ebx
    push eax
    
      
    push dword mesaj_citire
    call [printf]
    add esp, 4*1
    
    push nr
    push dword format_citire
    call [scanf]
    add esp,4*2
    
    mov ebx, [nr]
    pop eax
    add eax, ebx
    push eax
    
    
    push dword mesaj_citire
    call [printf]
    add esp, 4*1
    
    push nr
    push dword format_citire
    call [scanf]
    add esp,4*2
    
    mov ebx, [nr]
    pop eax
    add eax, ebx
    
    mov edx, 0
    mov ecx, 0
    mov cx,3
    div cx
    

    push eax
    push dword format_afisare
    call [printf]
    add esp, 4*2
    
    push dword 0
    call [exit]