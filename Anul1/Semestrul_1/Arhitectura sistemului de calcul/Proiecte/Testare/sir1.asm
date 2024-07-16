;Se citeste o propozitie de la tastatura. Sa se inverseze fiecare cuvant si sa se afiseze pe ecran.
bits 32
global start
import printf msvcrt.dll
import exit msvcrt.dll
import scanf msvcrt.dll
extern printf, exit, scanf
extern inv ; declarare eticheta de calclul din modulul secundar


segment data use32
    format_citire db "%[^.]", 0
    format_afisare db "%s", 0
    s resb 100
    max_len equ 100
    len db 0
    mesaj dd "Va rog sa introduceti o propozitie: ", 0
    rand_nou dd "",10,13
    aux resd 100 
    cuv resb 100 
    al_aux dd 2

    
segment code use32 public code

start:
            
        
        ;cd C:\Users\Paul0516\Desktop\Asc_editor\ASM_tools\Testare
        mov ebx,0
        push mesaj
        call [printf] ; afisare mesaj
        add esp, 4*1
        
        push s
        push dword format_citire
        call [scanf]
        add esp, 4 * 2 ; citire sir
        mov esi,s
        repeta1:
            lodsb
            cmp al, 0
            je sari
            mov [al_aux],al  ;am facut o variabia auxiliara pentru al deoarece o sa se piard valoarea cand accesam modulul secundar
            cmp al,32
            je daca
            jne altfel
            daca:
            
                mov edx, cuv
                push edx  ;punem cuvantul pe stiva
                mov dword [aux], esi ;salvam sirul din esi intr-o variabila auxiliara pentru ca o sa se modifice in modulul secundar
                call inv ;dupa ce am determinat cuvantul care trebuie inversat apelam functia din modulul secundar
                
                push ebx
                push format_afisare 
                call [printf] ;afisez cuvantul inversat
                add esp,4*2
                
                push rand_nou
                call [printf] ;afisez un rand nou
                add esp, 4*1
                
                mov esi, [aux] ;restaurez valoarea din esi
                mov ebx,0 
                jmp iesire
            altfel:
                 mov [cuv+ebx],al ;imi generez cuvantul care o sa fie inversat
                 inc ebx
            
            iesire:
            mov al,[al_aux]
        loop repeta1
        sari:
        
        mov edx, cuv
        push edx
        mov dword [aux], esi
        call inv
                
        push ebx
        push format_afisare
        call [printf]
        add esp,4*2

        ; exit(0)
        push dword 0      ; push the parameter for exit onto the stack
        call [exit]       ; call exit to terminate the program