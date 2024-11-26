; a) Sa se construiasca o functie care intoarce produsul atomilor numerici dintr-o lista, de la nivelul superficial.
 
;produs(list:lista) -> returneaza produsul tuturor numerelor din lista, ignorand subliste sau stringurie
; lista - lista de elemente primita de la utilizator

; Model matematic:
; produs([l1,l2,...,ln]) = {
;       1, daca lista este vida}  
;       l1 * produs([l2, ..., ln]), daca l1 este numar
;       produs([l2, ..., ln]), daca l1 nu este numar


;Model de flux:
; produs (i,o)
; i: lista de elemente
; o; numarul rezultat

(defun produs(lst)
  (cond
    ((null lst) 1) ; Cazul de baza cand lista este vida
    ((and (numberp (car lst)) (= (mod (car lst) 2) 0)) ; Cazul recursiv cand primul element este un numar
     (* (car lst) (produs (cdr lst)))) ; Returneaza primul element inmultit cu ceea ce mai urmeaza in lista
    (t ; Cazul recursiv cand primul element nu este un numar
     (produs (cdr lst)))) ; Ignora primul element si continua cu restul listei
)


; Cazuri de testare
; (produs '(1 2 3 4 5)) = 120
; (produs '(1 2 3 4 5 "a")) = 120
; (produs '(1 2 3 4 5 "a" (1 2 3))) = 120
; (produs '(1 2 3 4 5 "a" (1 2 3) 1 2 3)) = 720


; b) Sa se scrie o functie care, primind o lista, intoarce multimea tuturor perechilor din lista. De exemplu: (a b c d) --> ((a b) (a c) (a d)(b c) (b d) (c d))

; perechi(list:lista) -> returneaza toate perechile de elemente din lista
; lista - lista de elemente primita de la utilizator

; construire_perchi_de_la_o_pozitie_data(el, lst) -> returneaza toate perechile de elemente din lista, incepand cu elementul el
; el - elementul de la care incepem sa construim perechile
; lst - lista de elemente primita de la utilizator

; Model matematic:
; perechi([l1,l2,...,ln]) = {
;       [], daca lista este vida sau are un singur element
;       construire_perchi_de_la_o_pozitie_data(l1, [l2,...,ln]) (+) perechi([l2,...,ln]), altfel
; }

; construire_perchi_de_la_o_pozitie_data(el, [l1,l2,...,ln]) = {
;       [], daca lista este vida
;       (el, l1) (+) construire_perchi_de_la_o_pozitie_data(el, [l2,...,ln]), altfel
; }

;Model de flux:

; perechi(i,o)
; (i,o) 
; i: lista de elemente
; o: lista de perechi de elemente

; construire_perchi_de_la_o_pozitie_data(i,o)
; i: elementul de la care incepem sa construim perechile
; o: lista de elemente


(defun perechi (lst)
  (cond
    ((or (null lst) (null (cdr lst))) nil) ;; Cazul de baza daca lista este vida sau are un singur element se returneaza o lista vida
    (t (append ; Cazul recursiv cand lista are cel putin 2 elemente
         (construire_perchi_de_la_o_pozitie_data (car lst) (cdr lst)) ; Construim perechile de la primul element
         (perechi (cdr lst)))))) ; Continuam recursiv cu restul listei

(defun construire_perchi_de_la_o_pozitie_data (el lst)
  (cond
    ((null lst) nil) ; Casul de baza cand lista este vida se returneaza o lista vida
    (t (cons (list el (car lst)) ; Cazul recursiv cand lista are cel putin un element
             (construire_perchi_de_la_o_pozitie_data el (cdr lst))))))  ; construim o pereche dintre elementul dat ca si parametru si primul element din lista dupa care parcurgem lista mai departe


; Cazuri de testare
; (perechi '(a b c d)) = ((a b) (a c) (a d) (b c) (b d) (c d))
; (perechi '(a b c d 3)) = ((a b) (a c) (a d) (a 3) (b c) (b d) (b 3) (c d) (c 3) (d 3))
; (perechi '(a b c d 3 "ceva")) = ((a b) (a c) (a d) (a 3) (a "ceva") (b c) (b d) (b 3) (b "ceva") (c d) (c 3) (c "ceva") (d 3) (d "ceva") (3 "ceva"))


; c) Sa se determine rezultatul unei expresii aritmetice memorate in preordine pe o stiva. Exemple: 
; (+ 1 3) ==> 4 (1 + 3) 
; (+ * 2 4 3) ==> 11 ((2 * 4) + 3) 
; (+ * 2 4 - 5 * 2 2) ==> 9 ((2 * 4) + (5 - (2 * 2)) 


; eval-preorder(expr) -> returneaza rezultatul unei expresii aritmetice memorate in preordine pe o stiva
; expr - expresia aritmetica primita de la utilizator

; Model matematic:
; eval-preorder(E1, ... ,En) = {
;       E1, daca E1 este un numar
;       eval-preorder(E1) + eval-preorder(E2), daca expr este o lista si primul element este '+'
;       eval-preorder(E1) * eval-preorder(E2), daca expr este o lista si primul element este '*'
;       eval-preorder(E1) - eval-preorder(E2), daca expr este o lista si primul element este '-'
;       eval-preorder(E1) / eval-preorder(E2), daca expr este o lista si primul element este '/'
; }

;Model de flux:
; eval-preorder(i,o)
; i: expresia aritmetica
; o: rezultatul expresiei


(defun eval-preorder (expr)
  (cond
    ; Dacă este un număr (operand), returnează-l direct
    ((numberp expr) expr)
    
    ; Dacă este o listă, evaluăm primul element ca operator și restul ca operanzi
    ((listp expr)
     (let ((operator (car expr))          ; Operatorul este primul element
           (operands (cdr expr)))         ; Restul sunt operanzii
       (cond
         ((eq operator '+) (+ (eval-preorder (car operands))
                              (eval-preorder (cadr operands))))
         ((eq operator '*) (* (eval-preorder (car operands))
                              (eval-preorder (cadr operands))))
         ((eq operator '-) (- (eval-preorder (car operands))
                              (eval-preorder (cadr operands))))
         ((eq operator '/) (/ (eval-preorder (car operands))
                              (eval-preorder (cadr operands))))
         (t (error "Operator necunoscut: ~a" operator))))) ; Tratare eroare
    ; Dacă este altceva, dă eroare
    (t (error "Expresie invalidă: ~a" expr))))



; Cazuri de testare
; (eval-preorder '(+ 1 3)) = 4
; (eval-preorder '(+ (* 2 4) 3)) = 11
; (eval-preorder '(+ (* 2 4) (- 5 (* 2 2)))) = 9


; d) Definiti o functie care, dintr-o lista de atomi, produce o lista de perechi (atom n), unde atom apare in lista initiala de n ori. De ex:  (A B A B A C A) --> ((A 4) (B 2) (C 1)).

; numarare(el lst) -> returneaza de cate ori apare atom in lst
; el - elementul cautat
; lst - lista de elemente

; eliminare(el lst) -> elimina toate aparitiile lui atom din lst
; el - elementul cautat
; lst - lista de elemente

; creare_dictionar(lst) -> returneaza o lista de perechi (atom n) din lista initiala
; lst - lista de elemente

; Model matematic:
; numarare(el [l1,l2,...,ln]) = {
;       0, daca lista este vida
;       1 + numarare(el [l2,...,ln]), daca el = l1
;       numarare(el [l2,...,ln]), altfel
;}

; eliminare(el [l1,l2,...,ln]) = {
;       [], daca lista este vida
;       eliminare(el [l2,...,ln]), daca el = l1
;       l1 (+) eliminare(el [l2,...,ln]), altfel
;}

; creare_dictionar([l1,l2,...,ln]) = {
;       [], daca lista este vida
;       (l1, numarare(l1, [l1,l2,...,ln])) (+) creare_dictionar(eliminare(l1, [l1,l2,...,ln])), altfel
;}

;Model de flux:
; numarare(i,o)
; i: el cautat in lista de elemente
; o: numarul de aparitii al elementului in lista

; eliminare(i,o)
; i: el cautat in lista de elemente
; o: lista de elemente fara elementul cautat

; creare_dictionar(i,o)
; i: lista de elemente
; o: lista de perechi (atom n)



(defun numarare(el lst)
  (cond
    ((null lst) 0) ; Cazul de baza cand lista este vida se returneaza 0
    ((eq el (car lst)) (+ 1 (numarare el (cdr lst)))) ; Cazul recursiv cand elementul cautat este gasit in lista se incrementeaza numarul de aparitii
    (t (numarare el (cdr lst))))) ; Cazul recursiv cand elementul cautat nu este gasit in lista

(defun eliminare(el lst)
  (cond
    ((null lst) nil) ; Cazul de baza cand lista este vida se returneaza o lista vida
    ((eq el (car lst)) (eliminare el (cdr lst))) ; Cazul recursiv cand elementul cautat este gasit in lista se ignora elementul si se continua cu restul listei
    (t (cons (car lst) (eliminare el (cdr lst)))))) ; Cazul recursiv cand elementul cautat nu este gasit in lista se adauga elementul in lista rezultat si se continua cu restul listei

(defun creare_dictionar(lst)
  (cond
    ((null lst) nil) ; Cazul de baza cand lista este vida se returneaza o lista vida
    (t (let ((current (car lst))) ; Cazul recursiv cand lista are cel putin un element, se extrage primul element
         (cons (list current (numarare current lst)) ;; Creăm perechea
               (creare_dictionar (eliminare current lst))))))) ;; Procesăm restul

; Cazuri de testare

;(numarare 'A '(A B A B A C A))) = 4
;(numarare 'B '(A B A B A C A))) = 2
;(numarare 'C '(A B A B A C A))) = 1
;(numarare 'D '(A B A B A C A))) = 0

;(eliminare 'A '(A B A B A C A)) = (B B C)
;(eliminare 'B '(A B A B A C A)) = (A A A C A)
;(eliminare 'C '(A B A B A C A)) = (A B A B A A)
;(eliminare 'D '(A B A B A C A)) = (A B A B A C A)

; (creare_dictionar '(A B A B A C A)) = ((A 4) (B 2) (C 1))
; (creare_dictionar '(A B A B A C A 1 2 3 4 5 6 7 8 9 0)) = ((A 4) (B 2) (C 1) (1 1) (2 1) (3 1) (4 1) (5 1) (6 1) (7 1) (8 1) (9 1) (0 1))
