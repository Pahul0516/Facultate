;20. Sa se citeasca de la tastatura in baza 16 doua numere a si b de tip dword si sa se afiseze suma partilor low si diferenta partilor ;   high. Exemplu:
;    a = 00101A35h, b = 00023219h
;    suma = 4C4Eh
;    diferenta = Eh

bits 32

global start 
extern exit 
import exit msvcrt.dll
import printf msvcrt.dll
import scanf msvcrt.dll

extern printf
extern scanf

segment data use32 class=data
    mesaj1 db "Va rog sa introduceti primul numar in baza 16: ", 0
    mesaj2 db "Va rog sa introduceti al doilea numar in baza 16: ", 0
    nr1 resd 1
    nr2 resd 1
    
    format_citire db "%x", 0
    format_afisare1 db "Suma este: %x", 10, 0
    format_afisare2 db "Diferenta este: %x", 0
    
segment code use32 class=code

start:
    ;00101A35
    ;00023219
    push dword mesaj1
    call [printf]
    add esp, 4*1
    
    push dword nr1
    push dword format_citire
    call [scanf]
    add esp, 4*2
    
    push dword mesaj1
    call [printf]
    add esp, 4*1
    
    push dword nr2
    push dword format_citire
    call [scanf]
    add esp, 4*2
    
    mov eax, [nr1]
    mov ebx, [nr2]
    
    shl eax, 16
    shl ebx, 16
    shr eax, 16
    shr ebx, 16
    
    add eax, ebx 
    push eax
    push dword format_afisare1
    call [printf]
    add esp, 4*2
    
    mov eax, [nr1]
    mov ebx, [nr2]
    
    shr eax, 16
    shr ebx, 16
    
    sub eax, ebx 
    push eax
    push dword format_afisare2
    call [printf]
    add esp, 4*2
    
    push dword 0
    call [exit]