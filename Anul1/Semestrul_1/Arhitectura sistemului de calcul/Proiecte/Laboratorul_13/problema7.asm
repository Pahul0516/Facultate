bits 32

global start
extern exit
extern printf
extern scanf
extern fprintf
extern fread
extern fopen
import exit msvcrt.dll
import printf msvcrt.dll
import scanf msvcrt.dll
import fprintf msvcrt.dll
import fread msvcrt.dll
import fopen msvcrt.dll


segment data use32 class=data

     mod_aces db "r", 0
     fisier db "citire_p7.txt", 0
   
     format_afisare db "%d", 0
     len equ 100
     sir times len db 0
     
     
     format_citire db "%s", 0
     descriptor_fisier db 0
     

segment code use32 class=code
    
start:  

    push dword mod_aces
    push dword fisier
    call [fopen]
    add esp, 4*2
    
    mov [descriptor_fisier],eax

    cmp eax, 0
    je final
            
        push dword [descriptor_fisier]
        push dword len
        push dword 1
        push dword sir
        call [fread]
        add esp, 4*4
        
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
        push dword format_afisare
        call [printf]
        add esp, 4*2
    final:
    
    push dword 0
    call [exit]
    