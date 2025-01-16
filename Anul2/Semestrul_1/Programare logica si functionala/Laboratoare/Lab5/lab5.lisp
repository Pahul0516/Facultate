; 3. Se da un arbore de tipul (1). Sa se precizeze numarul maxim de niveluri din arbore. 

; maximum-depth (arb) -> returneaza numarul maxim de niveluri din arbore
; arb - lista cu arborele dat

; Model matematic:
; maximum-depth([l1,l2,...,ln]) = {
;       0 daca n = 0 (arborele este vid)
;       1, n = 1 (arborele are un singur nod)
;       1 + maximum-depth(l3, ... ln) daca l2 = 1
;       1 + max(maximum-depth(stang(l1, ... ln)), maximum-depth(drept(l1, ... ln)) ) daca l2 = 2

(defun maximum-depth (arb)
  (cond
    ((null arb) 0) ; dacă arborele este vid, se returnează 0
    ((null (cddr arb)) 1) ; daca exista dor un element in arbore se returneaza 1
    ((= (cadr arb) 1)
     (+ 1 (maximum-depth (cddr arb)))) ;daca al doilea element este 1 se calculeaza adancimea listei ramase
    ((= (cadr arb) 2) ; daca al doilea element este 2 se calculeaza adancimea maxima dintre subarborile stang si drept
     (+ 1 (max (maximum-depth (stang arb))
               (maximum-depth (dreapta arb))))))
  )

;Cazuri de testare:
;(maximum-depth '(A 0)) = 1
;(maximum-depth '(A 2 B 1 F 0 C 2 D 0 E 0)) = 3
;(maximum-depth '(A 1 B 1 C 1 D 1 E 1)) = 5
;(maximum-depth '(A 2 B 1 C 2 D 0 E 0 F 0)) = 4
;(maximum-depth '(A 2 B 2 D 1 G 0 E 2 H 1 L 2 M 0 N 0 I 0 C 1 F 2 J 0 K 1 Q 1 P 2 R 0 S 0)) = 7


; stang (arb) -> returneaza subarborele stang al arborelui
; arb - lista cu arborele dat

; Model matematic:
; stang([l1,l2,...,ln]) = {
;       parcurg_st(l1, ... ln, 0, 0)
;}

(defun stang (arb)
  (parcurg_st (cddr arb) 0 0))

; dreapta (arb) -> returneaza subarborele drept al arborelui
; arb - lista cu arborele dat

; Model matematic:
; dreapta([l1,l2,...,ln]) = {
;       parcurg_dr(l1, ... ln, 0, 0)
;}

(defun dreapta (arb)
  (parcurg_dr (cddr arb) 0 0))


; parcurg_dr (arb, nv, nm) -> returneaza subarborele drept al arborelui
; arb - lista cu arborele dat
; nv - numarul varfuri
; nm - numarul de muchii

; Model matematic:
; parcurg_dr([l1,l2,...,ln], nv, nm) = {
;       [], daca n = 0
;       l1...ln, daca nv = 1 + nm
;       l1 (+) l2 (+) parcurg_dr(l3, ... ln, nv + 1, l2 + nm)
;}

(defun parcurg_dr (arb nv nm)
  (cond
    ((null arb) nil)  ; daca lista e vida se returneaza 
    ((= nv (+ 1 nm)) arb)  ; returneaza lista ramasa cand numarul de varfuri este egal cu numarul de muchii + 1
    (t
     (parcurg_dr (cddr arb) (+ 1 nv) (+ (cadr arb) nm)))))  ; Continue traversal


; parcurg_st (arb, nv, nm) -> returneaza subarborele stang al arborelui
; arb - lista cu arborele dat
; nv - numarul varfuri
; nm - numarul de muchii

; Model matematic:
; parcurg_st([l1,l2,...,ln], nv, nm) = {
;       [], daca n = 0
;       [], daca nv = 1 + nm
;       l1 (+) l2 (+) parcurg_st(l3, ... ln, nv + 1, l2 + nm)
(defun parcurg_st(arb nv nm)
 (cond
 ((null arb) nil) ; daca lista e vida se returneaza  
 ((= nv (+ 1 nm)) nil) ; daca numarul de varfuri este egal cu numarul de muchii + 1 se returneaza lista vida
 (t (cons (car arb) (cons (cadr arb) (parcurg_st (cddr arb) (+ 1 nv) (+ (cadr arb) nm))))) 
)
)