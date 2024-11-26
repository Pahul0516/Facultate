% 12. Se da sirul a1,..., an format din numere intregi distincte. Se cere sa se 
% afiseze toate submultimile cu aspect de "munte"(o secvență se spune ca are 
% aspect de "munte" daca elementele cresc pana la un moment dat, apoi descresc. 
% De ex. 10 16 27 18 14 7). 

% subliste(L:list, Rez:list)
% L - multimea initiala
% Rez - submultime a multimii L

% Modelul matematic 
% subliste(l1,l2,..,ln) = {
% 			[] daca  L este vida 
% 			subliste(l2,l3,...,ln)
% 			l1 (+) subliste (l2,l3,..,ln)
% }


% Model de flux
% (i,o) - nedeterminist 
% i - multimea 
% o - fiecare submultime a multimii 
% nu putem sa avem modelul (i,i) deoarece in o sa sa fie de fiecare data
% o singura submultime generata la fiecare solutie


% Cazul de baza cand multimea este vida atunci si sublumtimea o sa fie tot vida 
subliste([], []).

% Cazul recursiv cand se exculde prima pozitie din lista
subliste([_|T], Subl) :-
    subliste(T, Subl).

% Cazul recursiv cand se include prima pozitie in submultime
subliste([H|T], [H|Subl]) :-
    subliste(T, Subl).

% cazuri de testare 
% subliste([],Rez).
% Rez = []
% subliste([1],Rez).
% Rez = []
% Rez = [1]
% subliste([1,2],Rez).
% Rez = []
% Rez = [2]
% Rez = [1]
% Rez = [1, 2]
% subliste([1,2,3],Rez).
% Rez = []
% Rez = [3]
% Rez = [2]
% Rez = [2, 3]
% Rez = [1]
% Rez = [1, 3]
% Rez = [1, 2]
% Rez = [1, 2, 3]



% is_mountain (L:list)
% L - lista pe care o verifica daca are sua nu structura de munte 

% Model matematic
% is_mountain(l1,l2,...,ln) = {
% crestere(l1,l2,..,ln, varf)
% descrestere(varf)
% }

% Model de flux - determinist
% (i) 
% i - este lista care urmeaza sa fie verificata

% functia in care se apeleaza verificarile pentru o lista daca creste
% daca funcita creste atunci in parametul Varf o sa ai o sublista 
% care contine toate elementele din dreapta elementului celui mai mare
% functia de descrestere doar verifica daca lista e strict descrescatoare
is_mountain([A, B | Rest]) :-
    verificare_crestere([A, B | Rest]), 
    extragere_varf([A, B | Rest], Varf), 
    verificare_descrestere(Varf).

% Cazuri de testare 
% is_mountain([]). - false
% is_mountain([1]). - false 
% is_mountain([1,2]). -false
% is_mountain([1,2,1]). -true
% is_mountain([1,2,1,1]). -false
% is_mountain([2,1,0]). -false
% is_mountain([1,2,1,0]). -true


% extragere_varf(l:list, varf:list)
% l - lista din care incearca sa determine varful
% varf - sublista a listei l unde se afla toate elementele din dreapta varsului

% Modelul matematic
% extragere_varf(l1,l2,...,ln, varf) = {
%          false daca l2>l1
%          l1 (+) crestere(l2,l3,...,l3) daca l1<l2
% }

% Model de flux - determinist
% (i1,i2)
% i1 - lista
% i2 - lista din dreapta varfului
%         		sau 
% (i,o)        		
% i - lista
% o - lista din dreapta varfului

% Cazul recursiv
extragere_varf([X, Y | T], Varf) :-
    X < Y,
    extragere_varf([Y | T], Varf).

% Cazul de baza 
extragere_varf([X, Y | T], [X, Y | T]) :-
    X > Y.


% Cazuri de testare
% extragere_varf([],Rez). -false
% extragere_varf([1],Rez). -false
% extragere_varf([1,2,1],Rez). = [2, 1]
% extragere_varf([1,2,1],[2, 1]). - true
% extragere_varf([1,2,3,4,3,2,3,4,1],Rez). = [4, 3, 2, 3, 4, 1]

% verificare_crestere(L:list)
% L - lista care este verificată să conțină cel puțin o pereche crescătoare

% Model matematic
% verificare_crestere(L1,l2,...,ln) = {
% 			true Dacă X < Y, înseamnă că am găsit o pereche crescătoare
% 			false daca lista L = lista vida
% 			verificare_crestere(l2,l3,...,ln)
% }

% Model de flux - determinist
% (i)

% Caz de baza
verificare_crestere([X, Y | _]) :- 
    X < Y, % Dacă X < Y, înseamnă că am găsit o pereche crescătoare și returnăm true
	!.

% Caz recursiv
verificare_crestere([_ | T]) :- 
    verificare_crestere(T).  % Continuăm să căutăm în restul listei

% Caz de baza
verificare_crestere([]) :- 
    fail.  % Lista goală nu poate avea pereche crescătoare, deci returnăm false

% Cazuri de testare
% verificare_crestere([]). -false
% % verificare_crestere([1]). - false
% verificare_crestere([2,1]). - false
% verificare_crestere([1,2,3,4,5]). - true

% descrestere(L:list)
% L - lista care este verificata sa fie strict descrescatoare

% Modelul matematic
% verificare_descrestere(l1,l2,...,ln) = {
%   	true - daca in lista exista doar un element
%   	descrestere(l2,l3,...,ln) daca l1>l2
% }

% Model de flux - determinist
% (i)
% i - lista care e verificata sa fie descrescatoare

% Cazul recursiv in care se parcurg elementele listei si se 
% returneaza fals daca nu respecta condicia de descendenta
verificare_descrestere([X, Y | Rest]) :-
    X > Y,
    verificare_descrestere([Y | Rest]).

% Cazul de baza unde se returneaza adevarat daca exista doar un element in lista
verificare_descrestere([_]).

% Cazuri de testare
% verificare_descrestere([]). - false
% verificare_descrestere([1]). - true
% verificare_descrestere([4,2,1]). -true
% verificare_descrestere([4,2,1,3]). -false


% mountain_sublists(List:lisr, Mountains:list of lists)
% list - multimea
% Mountains - lista de liste unde se stocheaza rezultatu.

% Model matematic
% mountain_sublists(L) = {
% 			findall(is_mountain(sublists(L)))
% }

% Model de flux - determinist
% (i1,i2)

% functia unde se apeleaza rezlovarea problemei
mountain_sublists(List, Mountains) :-
    findall(Subl, (subliste(List, Subl), Subl \= [], is_mountain(Subl)), Mountains).

% Cazuri de testare
% mountain_sublists([1,2,3,2,1],Rez).
% Rez = [
% [2, 3, 1],
% [2, 3, 2],
% [2, 3, 2, 1],
% [1, 2, 1],
% [1, 3, 1],
% [1, 3, 2],
% [1, 3, 2, 1],
% [1, 2, 1],
% [1, 2, 3, 1],
% [1, 2, 3, 2],
% [1, 2, 3, 2, 1]
% ]
