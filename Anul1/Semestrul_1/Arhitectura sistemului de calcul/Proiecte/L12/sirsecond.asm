;Se citeste de la tastatura un sir de caractere (litere mici si litere mari, cifre, caractere speciale, etc). 
;Sa se formeze un sir nou doar cu literele mici si un sir nou doar cu literele mari. Sa se afiseze cele 2 siruri rezultate pe ecran. 

bits 32

;declarare functii externe si variabile 

global _elementemici;functie cunoscuta la nivel global
global _elementemari;functie cunoscuta la nivel global

extern _printf;facem cunoscuta functia din c in programul asm

extern _rez1;facem cunoscuta variabila din c in programul asm
extern _rez2;facem cunoscuta variabila din c in programul asm


;segmentele de date si cod trebuie sa fie publice 

segment data public data use32

segment code public code use32

; codul ASM  pentru crearea celor 2 siruiri rez

;functia .asm care pune in _rez1 literele mici din sir
_elementemici:

;Entry code: Crearea cadrului de stiva
push ebp
mov ebp,esp

mov esi,[ebp+12];la [ebp+12] se afla adresa sirului de caractere citit de la tastatura
mov edi,_rez1
mov ecx,0
mov cl,byte[ebp+8];la [ebp+8] se afla numarul de elemente ale sirului de caractere

repeta:
lodsb;se extrage un caracter din sir 
cmp al,'a' ;se compara caracterul curent cu caracte a
    jge verificaz
    jl final
    verificaz:
        cmp al,'z' ;se compara caracterul cu z
            jle adauga
            jg final
                adauga:
                stosb
                final:
                loop repeta
                
;Return/Exit Code
;refacem cadrul de stiva pentru programul apelant
mov esp, ebp
pop ebp
ret

;functia care pune in _rez2 literele mari din sir
_elementemari:

;Entry code
;Crearea cadrului de stiva
push ebp
mov ebp,esp

mov esi,[ebp+12];la [ebp+12] se afla adresa sirului de caractere citit de la tastatura
mov edi,_rez2
mov ecx,0
mov cl,byte[ebp+8];la [ebp+8] se afla numarul de elemente ale sirului de caractere
repeta2:
    lodsb;se extrage un caracter din sir 
    cmp al,'A';compar caracterul cu A
    jge verificaZmare;
    jl final2;
    verificaZmare:
        cmp al,'Z';se compara caracterul cu Z
            jle adaugain2
            jg final2
                adaugain2:
                stosb;se adauga in _rez2 caracterul mare 
        final2:
loop repeta2

;Return/Exit Code
;refacem cadrul de stiva pentru programul apelant
mov esp, ebp
pop ebp
ret