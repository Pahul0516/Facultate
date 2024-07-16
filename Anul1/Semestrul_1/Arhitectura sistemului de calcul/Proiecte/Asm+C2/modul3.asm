bits 32

global _inversare
extern _printf

segment data use32 class=data
    format_string db "%s", 10, 13, 0
    
segment code use32 class=code

_inversare:
    ; entry code
    push ebp
    mov ebp, esp
    pushad
    ; entry code
    
    dec ecx
    mov esi, [ebp + 8] ; iau sirul de pe stiva
    mov edi, [ebp + 12]
    add esi, 1
    add edi, ecx  ; imi creez spatiu in memorie pentrul sirul inversat
    add edi, ecx  ; imi creez spatiu in memorie pentrul sirul inversat
    mov eax,0  
    stosb ; pun 0 la finalul sirului inversat
    
    repeta:
        cld
        lodsb
        std     ;inversez situl
        stosb
    loop repeta

    mov eax, 0
    stosb ; pun 0 la inceputul sirului inversat
    add edi, 2 

    ; exit code
    popad
    mov esp, ebp
    pop ebp
    ; exit code
    ret
