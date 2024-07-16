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

    fisier1 dd "citire_p1.txt", 0
    fisier2 dd "afisare_p1.txt", 0
    mod_acces1 dd "r", 0
    mod_acces2 dd "w", 0
    descriptor_fisier1 dd 0
    descriptor_fisier2 dd 0
    
    
    len equ 100
    sir_nr times len db 0 
    format_afisare dd "%d", 0
    
segment code use32 class=code
start:
    
    push dword mod_acces1
    push dword fisier1
    call[fopen]
    add esp ,4*2
    mov [descriptor_fisier1],eax

    push dword [descriptor_fisier1]
    push dword 1
    push dword len
    push dword sir_nr
    call [fread]
    add esp, 4*4
    
    push dword [descriptor_fisier1]
    call [fclose]
    add esp, 4*1
    
    push dword mod_acces2
    push dword fisier2
    call [fopen]
    add esp, 4*2
    
    mov [descriptor_fisier2],eax
    
    mov ecx, 10
    mov eax, 0
    push eax
    mov esi, sir_nr
    
    repeta:
        lodsb
        cmp eax, 0
        je afara
        mov ebx, eax 
        sub ebx, 30h
        pop eax 
        mul ecx
        add eax, ebx
        push eax
    jmp repeta
    afara:
    pop eax
    add eax, 2
    
    
    push eax
    push dword format_afisare
    push dword [descriptor_fisier2]
    call [fprintf]
    add esp, 4*2
    
    push dword 0
    call [exit]
