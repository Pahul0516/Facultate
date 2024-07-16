bits 32

global start 

extern exit

import exit msvcrt.dll
import fopen msvcrt.dll
import fclose msvcrt.dll
import printf msvcrt.dll
import scanf msvcrt.dll
import fprintf msvcrt.dll
import fscanf msvcrt.dll
import fread msvcrt.dll

extern fopen,fclose,printf,scanf,fprintf,fscanf,fread

segment data use32 class=data

    fisier1 db "citire_p5.txt", 0
    fisier2 db "afisare_p5.txt", 0
    mod_acces1 db "r", 0
    mod_acces2 db "w", 0
    format_citire db "%d", 0
    format_afisare db "%d", 0
    
    descrpitor_fisier1 resb 10
    descrpitor_fisier2 resb 10
    n resb 10
    nr resb 10
    
    len equ 100
    sir resb 100
    
segment code use32 class=code
start:
    
    push dword mod_acces1
    push dword fisier1
    call [fopen]
    add esp,4*2
    
    mov [descrpitor_fisier1], eax

    push dword mod_acces2
    push dword fisier2
    call [fopen]
    add esp,4*2
    
    mov [descrpitor_fisier2], eax
    
    push dword n
    push dword format_citire
    push dword [descrpitor_fisier1]
    call[fscanf]
    add esp, 4*3
    
    mov eax, 0
    mov ecx, [n]
        
    repeta:
        push ecx
        push eax
        push dword nr
        push dword format_citire
        push dword [descrpitor_fisier1]
        call[fscanf]
        add esp, 4*3
        pop eax
        add eax, [nr]
        pop ecx
    loop repeta
    
    push eax 
    push dword format_afisare
    push dword [descrpitor_fisier2]
    call [fprintf]
    add esp,4*3
    
    push dword 0
    call [exit]