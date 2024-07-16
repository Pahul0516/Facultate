bits 32
segment code use32 public code 

global suma

suma:

    mov esi, [esp + 4*1]
    mov edi, [esp + 4*2]
    mov ecx, [esp + 4*3]
    
    repeta:
        lodsd 
        cmp eax, 0
        je afara

        mov edx, 0
        repeta2:
            cmp eax, 0
            je afara2
            
            mov ebx, 0
            mov bl, al
            shl bl, 4
            shr bl, 4
            mov bh, 0
            movzx ebx, bx
            add edx, ebx
            
            mov ebx, 0
            mov bl, al
            shr bl, 4
            mov bh, 0
            movzx ebx, bx
            add edx, ebx
            
            shr eax, 8
            
        jmp repeta2
        afara2:
        
        mov eax, edx
        stosd
        
    jmp repeta
    afara
    
    ret 4*3
    