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



    fisier1 db "citire_p8.txt", 0
    mod_acces1 db "r", 0
    descriptor_fisier1 db 0
    
    fisier2 db "afisare_p8.txt", 0
    mod_acces2 db "w", 0
    descriptor_fisier2 db 0
    
    format_afisare db "%s", 0
    
    len equ 100
    sir times len resb 0
    noul_sir times len resb 0
   
    
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
        
        mov edi, noul_sir
        mov esi, sir 
        
        push dword [descriptor_fisier1]
        call [fclose]
        add esp, 4*1
        
        repeta:
            lodsb
            cmp eax, 'a'
            jae aici1
            jnae nu_e_litera_mica
            
            aici1:
                cmp eax, 'z'
                jbe aici2
                jnbe nu_e_litera_mica
            
            aici2:
                sub eax, 32
                stosb
                jmp gata
                

            nu_e_litera_mica:
            stosb
            gata:
            cmp eax, 0
            je afara 
        jmp repeta
        afara:
        
        push dword mod_acces2
        push dword fisier2
        call [fopen]
        add esp, 4*2
        
        mov [descriptor_fisier2], eax
        cmp eax, 0
        je final
        
        
        push dword noul_sir
        push dword format_afisare
        push dword [descriptor_fisier2]
        call [fprintf]
        add esp, 4*3
        
    final:

    push dword [descriptor_fisier2]
    call [fclose]
    add esp, 4*1
    
    push dword 0
    call[exit]

    


 