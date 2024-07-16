bits 32 

global start 

extern exit 
import exit msvcrt.dll
import scanf msvcrt.dll
import printf msvcrt.dll

extern scanf, printf

segment data use32 class=data

    mesaj1 db 10, "Numerele in baza 10 sunt: ", 0
    mesaj2 db "Numerele in baza 16 sunt: ", 0
    format_citire db "%d", 0
    format_afisare1 db "%d ", 0
    format_afisare2 db "%x ", 0
    rand_nou db 10

    
    nr resb 10
    cop resb 10
    len equ 10
    sir resb 100
    k dd 3

segment code use32 class=code

start:
    
    mov edi, sir

    repeta:
        push nr
        push format_citire
        call [scanf]
        add esp, 4*2
        mov cx, 10
        
        mov eax, [nr]
        mov [cop], eax
        
        cmp eax, 0
        je afara
        mov ebx, 0
        repeta2:
            cmp eax, 0
            je afara2
            mov edx,0
            div cx 
            add ebx, edx 
            
        jmp repeta2
        afara2:
        
        mov eax, [k]
        cmp ebx, eax
        je e_bun_de_adaugat
        jne nu_i_bun
        
        e_bun_de_adaugat:
            mov eax, [cop]
            stosb
        nu_i_bun: 
        
    jmp repeta
    
    afara:
    
    mov esi, sir
    
    push dword mesaj1
    call [printf]
    add esp, 4*1
    
    repeta3:
        lodsb 
        cmp eax, 0
        je afara3
        push eax
        push dword format_afisare1
        call [printf]
        add esp,4*2
    jmp repeta3
    
    afara3:
    
    push dword rand_nou
    call [printf]
    add esp, 4*1
    
    
    push dword mesaj2
    call [printf]
    add esp, 4*1
    
    mov esi, sir
    
    repeta4:
        lodsb 
        cmp eax, 0
        je afara4
        push eax
        push dword format_afisare2
        call [printf]
        add esp,4*2
    jmp repeta4
    
    afara4:
    
    push dword 0
    call [exit]