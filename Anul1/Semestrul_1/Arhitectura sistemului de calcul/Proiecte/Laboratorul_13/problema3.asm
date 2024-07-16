; 17. Sa se citeasca de la tastatura un numar in baza 10 si sa se afiseze valoarea acelui numar in baza 16
; 10. Sa se citeasca de la tastatura un numar in baza 10 si sa se afiseze valoarea acelui numar in baza 16.
;        Exemplu: Se citeste: 28; se afiseaza: 1C
bits 32 

global start
extern exit 
import exit msvcrt.dll
import scanf msvcrt.dll
import printf msvcrt.dll

extern scanf
extern printf


segment data use32 class=data
    mesaj db "Dati un numar: ", 0
    format_citire db "%d", 0
    nr resb 10
    
    format_afisare db "Numarul este %x", 0
    
segment code use32 class=code

start:
    
    push dword mesaj
    call [printf]
    add esp, 4*1
    
    push dword nr
    push dword format_citire
    call [scanf]
    add esp, 4*2
    
    mov eax, [nr]
    push eax
    push dword format_afisare
    call [printf]
    add esp, 4*2
    
    
    
    push dword 0
    call [exit]
