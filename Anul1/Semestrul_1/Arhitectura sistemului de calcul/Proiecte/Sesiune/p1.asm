bits 32

global start
extern exit
import exit msvcrt.dll
import printf msvcrt.dll
extern printf
extern suma

segment data use32 class=data
    formrat_afisare db "%x ", 0
    sir dd -1, 123456, 0abcdeffh, 0abcdeffh, 0cbcdeffh, 0dbcdeffh, 0111010101b, 0
    len equ ($-sir)/4
    sume resd len
    inceput resb 1
    lungime_maxi resb 1


segment code use32 class=code
start:
    
    push len
    push sume
    push sir 
    call suma
    
    mov esi, sume
    mov edx, 1
    
    repeta3:
        lodsd
        mov ebx, eax
        lodsd
        cmp ebx, 0
        je afara3
        cmp ebx, eax
        
        jbe aici
        jnbe acolo
        
        aici:
            inc ecx
            jmp peste
            
        acolo:
        
           mov [inceput], edx
           mov [lungime_maxi], ecx
        peste:
        
    jmp repeta3
    afara3:
    
    
    mov esi, sir
    add esi, [inceput]
    
    mov ecx, [lungime_maxi]
    
    ; repeta4:
        ; lodsd
        
        ; push eax
        ; push formrat_afisare
        ; call [printf]
        ; add esp, 4*2
        
    ; loop repeta4
    
    push dword 0
    call [exit]