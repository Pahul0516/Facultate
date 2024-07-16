; 16. Se da un fisier text. Sa se citeasca continutul fisierului, sa se contorizeze numarul de litere 'y' si 'z' si sa se afiseze aceaste valori. Numele fisierului text este definit in segmentul de date.

bits 32

global start 
extern exit 
import exit msvcrt.dll
import fprintf msvcrt.dll
import fopen msvcrt.dll
import fclose msvcrt.dll
import printf msvcrt.dll
import scanf msvcrt.dll
import fread msvcrt.dll

extern fprintf
extern fopen
extern fclose
extern printf
extern scanf
extern fread

segment data use32 class=data

    fisier1 dd "citire_p2.txt", 0
    fisier2 dd "afisare_p2.txt", 0
    mod_acces1 dd "r", 0
    mod_acces2 dd "w", 0
    descriptor_fisier1 dd 0
    descriptor_fisier2 dd 0
    
    len equ 100
    sir times len db 0
    format_afisare dd "Numarul de 'y' si 'z' este: %d", 0
    
segment code use32 class=code
start:
    
    push dword mod_acces1
    push dword fisier1
    call [fopen]
    add esp, 4*2
    
    mov [descriptor_fisier1],eax
    
    push dword mod_acces2
    push dword fisier2
    call [fopen]
    add esp, 4*2
    
    mov [descriptor_fisier2],eax
    
    push dword [descriptor_fisier1]
    push dword 1
    push dword len
    push dword sir
    call [fread]
    add esp, 4*4
    
    mov ecx, 0
    mov esi, sir
    repeta:
        lodsb
        cmp eax, 0
        je afara
        
        cmp eax, 'y'
        je adauga
        
        cmp eax, 'z'
        je adauga
        jne nu_i_bun
        
        adauga:
            inc ecx
        nu_i_bun:
        
    jmp repeta
    afara:
    
    push ecx
    push dword format_afisare
    push dword [descriptor_fisier2]
    call [fprintf]
    add esp, 4*3
    
    push dword[descriptor_fisier1]
    call [fclose]
    add esp, 4*1
    push dword[descriptor_fisier2]
    call [fclose]
    add esp, 4*1
    
    push dword 0
    call [exit]
