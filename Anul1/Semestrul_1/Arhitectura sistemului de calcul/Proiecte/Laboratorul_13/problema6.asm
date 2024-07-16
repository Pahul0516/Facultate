bits 32

global start 
extern exit 
import exit msvcrt.dll
import printf msvcrt.dll
import scanf msvcrt.dll
import fprintf msvcrt.dll
import fopen msvcrt.dll

extern printf
extern scanf
extern fprintf
extern fopen

segment data use32 class=data
    
    mesaj db "Va rog sa introduceti un sir de caractere: ", 0
    format_citire db "%[^.]",0
    format_afisare db "%d", 0
    sir resb 100

    fisier db "afisare_p6.txt", 0
    mod_acces db "w", 0
    descriptor_fisier db 0
    
    
segment code use32 class=code
start:

    push dword mesaj
    call [printf]
    add esp, 4*1
    
    push dword sir
    push dword format_citire
    call [scanf]
    
    mov esi, sir
    mov eax, 0
    mov ecx, 0
    
    repeta:
        lodsb 
        
        cmp eax, "a"
        je este_vocala
 
        cmp eax, "e"
        je este_vocala

        cmp eax, "i"
        je este_vocala

        cmp eax, "o"
        je este_vocala
        
        cmp eax, "u"
        je este_vocala
        jne este_consoala

        este_vocala:
            inc ecx
            jmp afara
        este_consoala:
        
        cmp eax, 0
            je este_punct
            
        afara:
    jmp repeta
    
    este_punct:
    
    push ecx
    
    push dword mod_acces
    push dword fisier
    call [fopen]
    add esp, 4*2
    
    pop ecx
    
    mov [descriptor_fisier],eax
    cmp eax,0 
    je final
    
        push dword ecx
        push dword format_afisare
        push dword [descriptor_fisier]
        call [fprintf]
        add esp, 4*3
        
    final:
    
    
    
    push dword 0
    call [exit]