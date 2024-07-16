bits 32 ; assembling for the 32 bits architecture

; functia _is_prime va fi disponibila altor unitati de compilare
global _is_prime        

; linkenditorul poate folosi segmentul public de date si pentru date din afara
segment data public data use32

; codul scris in asamblare este dispus intr un segment public, posibil a fi partajat cu alt cod extern
segment code public code use32
_is_prime:
    ; creare cadru de stiva pentru programul apelat
    push ebp
    mov ebp,esp
    
    ; obtinem argumentul transmis pe stiva functiei is_prime
    ; la locatia [ebp+4] se afla adresa de return 
    ; la locatia [ebp] se afla valoarea ebp pentru apelant
    
    mov eax, [ebp+8] ; eax=A
    
    
    ;cod asm pentru verificare daca EAX e prim
    
    cmp eax,1     ; scadere fictiva eax-2
    jle not_prime ; daca este mai mic decat 1, nu este prim => salt la      not_prime
                  ; altfel, continue
    
    mov ecx, eax  ; se salveaza in ecx continutul din eax (adica numarul A)
    
    mov ebx,2     ; d=2
    repeta:
        cmp ebx, ecx  ; scadere fictiva eax-ecx, adica d*d-A
        je prime       ; daca d*d>x, atunci numarul x este prim, deci nu mai avem cazuri de verificat
                      ; altfel, continue
        
        mov eax, ecx
        cdq 
        div ebx
        cmp edx,0 
        je not_prime  ; daca ax(restul impartirii lui A la d) este 0, atunci A e divizibil cu d, deci nu este prim => salt la not_prime
                      ; altfel, continue
        inc ebx
    jmp repeta    
    
    prime: 
        mov eax,1
    jmp final
   
   not_prime:
        mov eax,0
    final:
    
    
    ; refacem cadrul de stiva pentru programul apelant
    mov esp, ebp
    pop ebp
    
    ret 
    ; conventie cdecl - este responsabilitatea programului apelant sa elibereze parametrii transmisi
    
