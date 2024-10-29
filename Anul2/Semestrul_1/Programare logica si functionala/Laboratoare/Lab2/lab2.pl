% 8. a) Definiti un predicat care determina succesorul unui numar reprezentat cifra cu cifra intr-o lista. De ex: [1 9 3 5 9 9] => [1 9 3 6 0 0]

% succesor(list:list, Result:list)  
% list - lista pe care o primeste de la utilizator
% Rez - succesorul numarului sub forma de lista
% Predicatul principal care adaugă 1 la lista reprezentând un număr
succesor(List, Result) :-
    reverse(List, ReversedList),            % Inversăm lista pentru a lucra de la coada spre cap
    add_one(ReversedList, NewReversedList), % Adăugăm 1 la listă
    reverse(NewReversedList, Result).       % Inversăm rezultatul final pentru a obține lista în ordine corectă

% add_one(L:list,Rez:list)
% list - lista pe care o primeste de la utilizator
% Rez - succesorul numarului sub forma de lista

% Model matematic
% add_one(l,Rez) = {
% 		[1] daca l = [] (daca lista este vida atunci punem 1 in lista)
% 		l1+1 daca l1+1<10 
% 		add_one(l2,l3...Ln,Rez)
% }

% Modelul de flux
% (i1,i2)
% i1 - lista pe care o primim ca si parametru 
% i2 - rezultatul pe care il ofer tot ca si parametru 

% Exemple de testare:
% succesor([], [1]).
% succesor([0], [1]).
% succesor([1,2,3], [1,2,4]).
% succesor([1,2,9], [1,3,0]).
% succesor([1,9,9], [2,0,0]).

% Cazul de bază: dacă ajungem la o listă vidă și mai avem un carry
% adăugăm 1 la începutul listei.
add_one([], [1]).
    
% Cazul în care cifra plus 1 este mai mică de 10, deci nu trebuie să "carăm".
% Aici foarte important, dupa ce am adaugat 1 am facut o taietura deoarece am gasit rezultatul
add_one([Digit | Rest], [NewDigit | Rest]) :-
    NewDigit is Digit + 1,
    NewDigit < 10,
    !.

% Cazul în care cifra plus 1 este 10 sau mai mare, deci avem nevoie de "carry".
% Se apeleaza [0 | NewRest] deoarece cand o cifra trece de 9 punem 0 pe pozitia respectiva si trecem la urmatoarea cifra
add_one([Digit | Rest], [0 | NewRest]) :-
    NewDigit is Digit + 1,
    NewDigit == 10,
    add_one(Rest, NewRest).


% b)Se da o lista eterogena, formata din numere intregi si liste de cifre. 
% Pentru fiecare sublista sa se determine succesorul numarului reprezentat 
% cifra cu cifra de lista respectiva. De ex:  
% [1, [2, 3], 4, 5, [6, 7, 9], 10, 11, [1, 2, 0], 6] =>  
% [1, [2, 4], 4, 5, [6, 8, 0], 10, 11, [1, 2, 1], 6] 

% procesare_lista(L:list, Rez:list)
% l - lista primita de la utilizaotr
% Rez - rezultatul listei eterogene unde fiecare sublista contine succesorul

% Model matemeatic
% procesare_lista(L,Rez) = { 
% 		[] daca L = []
% 		procesare_lista(L2,L3,...Ln, Rez) daca L1 nu e lista
% 		succesor(l1,Rez2) (+) procesare_lista(L2,L3,...Ln, Rez)
% }

% Modelul de Flux
% (i1,i1)
% i1 - lista data de utiliztor
% i2 - lista rezultata care e tot data de utiliztor

% Exemple de testare:
% procesare_lista([], [] ).
% procesare_lista([1,2,3], [1,2,3] ).
% procesare_lista([1,[1],2,3], [1,[2],2,3]).
% procesare_lista([1,[9],2,3], [1,[1,0],2,3]).
% procesare_lista([1,[9,9,9],2,3], [1,[1,0,0,0],2,3]).
% procesare_lista([1, [2, 3], 4, 5, [6, 7, 9], 10, 11, [1, 2, 0], 6],[1, [2, 4], 4, 5, [6, 8, 0], 10, 11, [1, 2, 1], 6]).


% Caz de bază: lista goală deci se returneaza tot o lista goala
procesare_lista([], []).  


% Caz recursiv: daca primul element nu e lista se merge mai departe
procesare_lista([H | T], [H | Result]) :-  
    \+ is_list(H),                        
    procesare_lista(T, Result).          


% Caz recursiv: daca primul element e lista atunci ii calculam succesorul si se merge mai departe
procesare_lista([H | T], [Succesor | Result]) :-  
    is_list(H),                             
    succesor(H, Succesor),                   
    procesare_lista(T, Result).             

