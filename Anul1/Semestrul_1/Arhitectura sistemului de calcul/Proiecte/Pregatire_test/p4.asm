; se citeste un caracter si un nume de fisier, sa se caute in fisier caracterul si sa se 
; afiseze pe ecran pozitia unde a fost gasit prima oara

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

extern fopen, fclose, printf, scanf, fprintf, fscanf, fread

segment data use32 class=data
    
    mod_acces db "r", 0
    mesaj1 db "Va rog sa introduceti caracterul: ", 0
    mesaj2 db "Va rog sa introduceti fisierul din care se face citirea: ", 0
    format_citire db "%s", 0
    format_afisare db "Pozitia caracterului este: %d", 0
    
    descriptor_fisier resb 20
    caracter resb 20
    fisier resb 20
    
    len equ 100
    sir resb 100
    
    
    
segment code use32 class=code

start:

    push mesaj1
    call [printf]
    add esp, 4*1
    
    push dword caracter
    push dword format_citire
    call [scanf]
    add esp, 4*2
    
    push mesaj2
    call [printf]
    add esp, 4*1
    
    push dword fisier
    push dword format_citire
    call [scanf]
    add esp, 4*2
    
    mov esi, fisier
    
    push dword mod_acces
    push esi
    call [fopen]
    add esp, 4*2
    
    mov [descriptor_fisier],eax
    
    push dword [descriptor_fisier]
    push dword 1
    push dword len
    push dword sir
    call [fread]
    add esp, 4*4
        
    mov ecx, 1
    mov esi, sir
    
    repeta:
        lodsb
        cmp eax, 0
        je afara
        
        cmp eax, [caracter]
        je afara
        inc ecx
        
    jmp repeta
    afara: 
    
    
    push ecx
    push format_afisare
    call [printf]
    add esp, 4*1
    
    push dword 0
    call [exit]
