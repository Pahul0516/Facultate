bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    a db 'abcd'
    cuv resb 100

; our code starts here
segment code use32 class=code
    start:
        ; ... 
        mov esi,a
        mov edx,0
        lea esi,[esi+3]
        std
        repeta:
            lodsb
            cmp al,0
            je iesi
            mov [cuv+edx],al
            inc edx
            
        jmp repeta
        iesi:
        mov ebx, cuv
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
