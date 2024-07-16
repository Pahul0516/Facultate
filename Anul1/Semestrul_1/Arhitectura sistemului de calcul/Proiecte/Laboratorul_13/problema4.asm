; 18. Sa se citeasca de la tastatura un numar in baza 10 si un numar in baza 16. Sa se afiseze in baza 10 numarul de biti 1 ai sumei celor doua numere ; ;      citite. Exemplu:
;       a = 32 = 0010 0000b
;       b = 1Ah = 0001 1010b
;       32 + 1Ah = 0011 1010b
;       Se va afisa pe ecran valoarea 4.

bits 32 

global start
extern exit
import exit msvcrt.dll
import scanf msvcrt.dll
import printf msvcrt.dll

extern scanf
extern printf


segment data use32 class=data
    mesaj1 db "Va rag sa introduceti un numar in baza 10: ", 0
    mesaj2 db "Va rag sa introduceti un numar in baza 16: ", 0
    nr1 resb 10
    nr2 resb 10
    format_citire1 db "%d", 0
    format_citire2 db "%x", 0
    
    format_afisare db "Suma este: %d", 0
    rand_nou db 10, 0
    format_afisare2 db "Numarul de biti este %d", 0
    
    masca db 00000001

segment code use32 class=code

start:
    mov eax, 0
    push dword mesaj1
    call [printf]
    add esp, 4*1
    
    push dword nr1
    push dword format_citire1
    call[scanf]
    add esp,4*2
    
    push dword mesaj2
    call [printf]
    add esp, 4*1
    
    push dword nr2
    push dword format_citire2
    call[scanf]
    add esp,4*2
    
    mov eax, [nr1]
    mov ebx, [nr2]
    add eax, ebx
    
    push eax
    push eax
    push dword format_afisare
    call [printf]
    add esp, 4*2
    push dword rand_nou
    call [printf]
    add esp, 4*1
    pop eax
    
    mov ebx, [masca]
    mov ecx, 0
    repeta: ;0011 1010b
    
        push eax
        and eax, ebx
        cmp eax, 0
        je peste
            inc ecx 
        peste:
        shl ebx, 1
        pop eax
        
    cmp ebx, 256
    jne repeta
    je afara
    afara:
    
    push ecx
    push dword format_afisare2
    call [printf]
    add esp, 4*2
    
    push dword 0
    call [exit]