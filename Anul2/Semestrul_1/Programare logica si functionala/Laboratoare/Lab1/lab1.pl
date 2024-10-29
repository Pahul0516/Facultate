%5. a. Sa se scrie un predicat care sterge toate aparitiile unui anumit
% atom dintr-o lista.


% sterge_lista(E:integer, L:list, Rez: list)// returneaza in Rez elementele din prima lista
% mai putin cele egale cu E.


% Model matematic
% sterge_lista(E,L,Rez)={
%						[] daca L == [] (nu putem sa eliminam elemente dintr-o lista vida)
%						l1 (+) sterge_lista(E, l2,l3...Ln , Rez) daca L1 != E
%						sterge_lista(E, l2,l3...ln, Rez) altfel
%				       }


% Model de fux
% (i1,i2,o1)
% i1 - elementul dat de utiliztor
% i2 - lista data de utilizator
% o1 - lista returnata de program


% Exemple de testare
% sterge_lista(1,[],[]).
% sterge_lista(1,[1],[]).
% sterge_lista(1,[1,1,1],[]).
% sterge_lista(2,[1,2,1],[1,1]).
% sterge_lista(2,[1,2,2],[1]).
% sterge_lista(3,[1,2,3,4,5],[1,2,4,5]).
% sterge_lista(3,[5,5,5,5,5,5,5],[5,5,5,5,5,5,5]).



% Cazul de baza: cand stergi dintr-o lista vida se obtine tot o lista vida
sterge_lista(_, [], []).

% Recursivitate: daca Head-ul e diferit de element atunci il adaugam in lista rezultat
sterge_lista(Elem, [H | T], [H1 | Rez]) :-
    H \= Elem,
    sterge_lista(Elem, T, Rez),
	H1 is H * 2.

% Recursivitate: daca Head-ul e egal cu elementul atunci nu il adaugam in lista rezultat
sterge_lista(Elem, [H | T], Rez) :-
    H = Elem,
    sterge_lista(Elem, T, Rez).


% b. Definiti un predicat care, dintr-o lista de atomi, produce o lista de perechi (atom n),
% unde atom apare in lista initiala de n ori.
% De ex: numar([1, 2, 1, 2, 1, 3, 1], X) va produce X = [[1, 4], [2, 2], [3, 1]].

% numarare(L:List, E:intiger, Rez: intiger)
% L - lista in care se cauta elementul E,
% E - elementul pentru care se face numarare
% Rez - numarul de aparitii al elementului E in Lista

% Model matematic
% numarare(L,E,Rez)={
%						0 daca L == [] (daca lista e vida inseamna ca nu putem sa aven nicio aparitie)
%						1 + numarare(L2,L3,..Ln, E , Rez) daca L1 == E
%						numarare(L2,L3,..Ln, E , Rez) altfel
%				       }

% Model de fux
% (i1,i2,o1)
% i1 - lista data de utilizator
% i2 - elementul dat de utiliztor
% o1 - valoarea returnata de program

% Exemple de testare
% numarare([],1,0).
% numarare([1],2,0).
% numarare([1],1,1).
% numarare([1,1],1,2).
% numarare([1,1,2,2,3,3,3,4],3,3).

% Cazul de baza: daca lista e vida atunci nu ai ce sa numeri
numarare([], _, 0).

% Recursivitate: daca Head-ul e egal cu elementul atunci cresti numarul de aparitii si treci la urmatoarea valoare din lista
numarare([H|T], Elem, Nr_aparitii):-
    Elem = H,
    numarare(T,Elem,Nr_aparitii1),
	Nr_aparitii is Nr_aparitii1 + 1.

% Recursivitate: daca Head-ul nu e egal cu elemntul cautat atunci treci la urmatoarea valoare din lista
numarare([H|T], Elem, Nr_aparitii):-
    Elem \= H,
    numarare(T,Elem,Nr_aparitii).


% creare_dictionar(L1:List, L2:List)
% L1 - lista care contine toate elementtlee in ordine aleatorie
% L2 - lista in care se va returna dictionarul

% Model matematic
% creare_dictionar(L1,L2)={
%						[] daca L1 == [] (daca lista e vida inseamna ca si dictionarul va fi tot vid)
%						[L1,numarare(l) ()creare_dictionar(sterge_lista(E,L1,Rez), dictionar) daca L1 != (lista_vida) (altfel)
%						(aici sterge_lista(E,L1,Rez) returneaza in Rez o lista mai mica, de unde apare si apelul recursiv)
%				       }

% Model de fux
% (i1,o1)
% i1 - lista data de utilizator
% o1 - dictionarul returnat de program


% Exemple de testare
% creare_dictionar([], []).
% creare_dictionar([1], [[1,1]]).
% creare_dictionar([1, 1], [[1, 2]]).
% creare_dictionar([1,2,3,4,5,5,5], [[1,1],[2,1],[3,1],[4,1],[5,3]]).
% creare_dictionar([1,1,1,1,5,5,5,5], [[1,4],[5,4]]).

% Cazul de baza: daca lista e vida atunci nu ai ce dictionar sa returnezi
creare_dictionar([], []).

% Recursivitate: daca lista data de utilizator nu e vida, se tot elimina elemente cu fucntia sterge_lista(H, T, NewList), pana cand lista ajunge vida
creare_dictionar([H|T], [[H, Count]|Rez]) :-
    numarare([H|T], H, Count),
    sterge_lista(H, T, NewList),
    creare_dictionar(NewList, Rez).

