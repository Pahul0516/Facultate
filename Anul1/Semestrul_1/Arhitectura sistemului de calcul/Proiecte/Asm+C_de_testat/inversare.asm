bits 32

global _inversare
extern _printf
extern _rez

segment data use32 class=data
    format_string db "%s", 10, 13, 0
    
segment code use32 class=code

_inversare:
    ; entry code
    push ebp
    mov ebp, esp
    
    ; entry code
    
    dec ecx
    mov esi, [ebp + 8] ; iau sirul de pe stiva
    mov edi, _rez
    add edi, ecx
    add edi, ecx
    add esi, 1
    mov eax,0  
    stosb ; pun 0 la finalul sirului inversat
    sub edi,1
    
    repeta:
        cld
        lodsb
        std     ;inversez situl
        stosb
    loop repeta
    mov eax, 0
    stosb ; pun 0 la inceputul sirului inversat
    add edi, 2 
    mov eax, edi
    
    ; push edi
    ; push dword format_string
    ; call _printf
    
    ; exit code
    mov esp, ebp
    pop ebp
    ; exit code
    ret
