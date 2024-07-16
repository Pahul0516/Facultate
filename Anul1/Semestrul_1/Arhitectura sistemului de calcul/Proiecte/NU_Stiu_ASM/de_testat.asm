bits 32
global start
import printf msvcrt.dll
import exit msvcrt.dll
import scanf msvcrt.dll
extern printf, exit, scanf

segment data use32 class=data
    cuvant db "Ana are mere", 0
    format_string db "%s", 0
    invers resb 100

segment code use32 public code class=code

start:
    mov esi, cuvant
    mov edi, invers+12
    mov ecx, 12
    repeta:
        cld
        lodsb
        std
        stosb
    loop repeta
    add edi,1
    ; mov byte [edi], 0  ; Null-terminate the reversed string
    push edi
    push dword format_string
    call [printf]

    push dword 0      ; Push the parameter for exit onto the stack
    call [exit]       ; Call exit to terminate the program
