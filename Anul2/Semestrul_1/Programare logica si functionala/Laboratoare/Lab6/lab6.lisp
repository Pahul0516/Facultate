; 2. Definiti o functie care obtine dintr-o lista data lista tuturor atomilor care apar, pe orice nivel, dar in aceeasi ordine. 
; De exemplu  
; (((A B) C) (D E)) --> (A B C D E)

;; make_one_list (l) -> returneaza lista tuturor atomilor care apar
; l - lista de liste


; Model matematic:
; make_one_list(l1,l2,...,ln) = {
;       U(reuniune cand i = 1 -> n) make_one_list(l)     daca l1 e lista
;       l1 daca l e atom 


(defun make_one_list(l)
  (mapcan ; functie care parcurge fiecare element, aplica o functie asupra fiecarui element si le concateneaza la final
    #'(lambda (x)  ; functia anonima lambda pentru fiecare element din l
    (cond 
      ((listp x) (make_one_list x)) ; daca elementul e lista atunci se face apel recursiv pentur elementul lista
      (t (list x)) ; cazul de baza cand se returneaza elementul care nu e lista
    ) 
    )
  l
  )
)

;Cazuri de testare:

;(make_one_list '(((A B) C) (D E))) = (A B C D E)
;(make_one_list '(A B C D E)) = (A B C D E)
;(make_one_list '( (A) (B) (C) (D) (E) () )) = (A B C D E)
;(make_one_list '()) = NIL
;(make_one_list '((((((A))))))) = (A)