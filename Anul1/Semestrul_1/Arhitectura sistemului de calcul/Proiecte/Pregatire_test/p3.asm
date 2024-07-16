bits 32

global start 
extern exit
import exit msvcrt.dll

import fread msvcrt.dll
import fprintf msvcrt.dll
import fopen msvcrt.dll
import fclose msvcrt.dll
extern fread, fprintf, fopen,fclose

segment data use32 class=data



    fisier1 db "citire_p3.txt", 0
    mod_acces1 db "r", 0
    mod_acces2 db "w", 0
    format_afisare db "%s",0
    descriptor_fisier1 resb 100
    descriptor_fisier2 resb 100
    
    len equ 100
    sir times len resb 0
    fisier2 db "", 0
    afisare db "",0
    

   
    
segment code use32 class=code
start:
    push dword mod_acces1
    push dword fisier1
    call [fopen]
    add esp, 4*2
    
    mov [descriptor_fisier1],eax
    
    cmp eax, 0
    je final
        
        push dword [descriptor_fisier1]
        push dword 1
        push dword len
        push dword sir
        call [fread]
        add esp, 4*4
        
        mov esi, sir
        mov edi, fisier2
        add edi, 50
        
        repeta:
            lodsb 
            cmp eax, 10
            je afara
            stosb
        
        jmp repeta
        afara:
        
        mov eax,'.'
        stosb
        mov eax, 't'
        stosb
        mov eax, 'x'
        stosb
        mov eax, 't'
        stosb
        
 
        
        mov esi, fisier2
        add esi, 50
        
        push dword mod_acces2
        push esi
        call [fopen]
        add esp,4*2
        mov [descriptor_fisier2], eax
        
        mov esi, sir
        mov edi, afisare
        add edi, 200
        mov edx, 0
        mov eax, 0
        
        repeta2:
            lodsb 
            cmp eax, 0
            je afara2
            
            cmp eax, 10
            je e_ok
            jne nu_e_ok
            
            e_ok:
                mov edx, 1
                jmp nu_i_nevoie

            nu_e_ok:
                          
            cmp edx, 1
            je adaugam
            jne nu_i_nevoie
            adaugam:
                cmp eax, " "
                je aici
                jne acolo
                aici:
                    mov eax, "S"
                    stosb
                    jmp mai_departe
                acolo:
                    stosb
                mai_departe:
            nu_i_nevoie:
            
        
        jmp repeta2
        afara2:
        
    final:
    
    mov esi, afisare
    add esi, 200
    
    push esi
    push dword format_afisare
    push dword [descriptor_fisier2]
    call [fprintf]
    add esp, 4*3
    
    push dword[descriptor_fisier2]
    call [fclose]
    add esp,4*1

    push dword 0
    call[exit]

    


 