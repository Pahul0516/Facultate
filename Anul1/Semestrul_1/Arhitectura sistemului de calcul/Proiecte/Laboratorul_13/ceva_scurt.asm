;Se da un fisier text. Sa se citeasca continutul fisierului, sa se determine litera mica (lowercase) cu cea mai mare frecventa si sa se afiseze acea ;litera, impreuna cu frecventa acesteia. Numele fisierului text este definit in segmentul de date.



bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit           ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions
                          
extern exit, fopen, fclose, fscanf, printf, fread,fprintf
import fopen msvcrt.dll
import fclose msvcrt.dll
import fscanf msvcrt.dll
import printf msvcrt.dll
import fread msvcrt.dll
import fprintf msvcrt.dll

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...
    
    nume_fisier db 'citire.txt',0
    mod_acces db 'r',0
    descriptor_fisier db -1
    
    format dd '%s', 0
    len equ 100
    sir  times len db 0
    lun db 0
    fr dd 0
    caracter dd 0
    text db 'Litera este %c si apare de %d ori', 0
    

; our code starts here
segment code use32 class=code
    start:
        ; ...
        
        
        push dword mod_acces
        push dword nume_fisier
        call[fopen]
        add esp, 4*2

        cmp eax, 0
        
        je final
            
            mov [descriptor_fisier], eax
            
            ; eax = fread(text, 1, len, descriptor_fis)
            
            push dword [descriptor_fisier]
            push dword len
            push dword 1
            push dword sir
            call [fread]
            add esp, 4*4
            
            mov ebx, 97
            
            repeta1:
            
                mov edx,0
                mov edi,0
                mov esi, sir
                mov ecx, len
                repeta2:
                    lodsb 
                    cmp eax,ebx
                    je then
                    jne els
                    
                    then:
                    
                        add edi,1
                        mov edx, ebx
                        
                    els: 
                        
                    
                loop repeta2
                
                
                cmp edi,[fr]
                ja then2
                jbe els2
                then2:
                    mov [fr], edi
                    mov [caracter], edx
                els2:
                
                add ebx,1
                cmp ebx, 123
                je final_loop
                
            jmp repeta1
            
            final_loop:
           
            
            mov eax,dword[fr]
            mov ebx,dword[caracter]
          
            push eax
            push ebx
            push dword text
            call [printf]
            add esp, 4*3
           
            
            push dword [descriptor_fisier]
            call[fclose]
            add esp, 4*1
            
        final:
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program