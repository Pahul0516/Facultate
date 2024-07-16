
bits 32
global inv ; eticheta

segment data use32  
  cuvant resb 100
  
segment code use32 public code

inv:

 mov edx,0
 dec ebx
 mov esi, [esp + 4]  
 lea esi, [esi + ebx] 
 mov ecx,100
 
 curata:
    mov [cuvant+edx],byte 0
    inc edx
 loop curata
 
 mov edx,0
 std
 repeta:
    lodsb 
    cmp al,0
    je iesi
    mov [cuvant+edx],al
    inc edx
 jmp repeta
 iesi:
 mov ebx, cuvant
 cld
 ret 4*1