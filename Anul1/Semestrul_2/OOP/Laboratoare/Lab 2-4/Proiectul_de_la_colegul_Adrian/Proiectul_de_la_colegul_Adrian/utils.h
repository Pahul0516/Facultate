#pragma once
#include "Oferta.h"

/*
 * functia ce determina daca o oferta indeplineste conditia de filtrare dupa destinatie
 * o - Oferta* (pointer catre adresa de memorie din heap unde este salvata oferta alocata dinamic)
 * text - char* (pointer catre un sir de caractere ce contine textul in functie de care are loc filtrarea)
 * returneaza 1 daca oferta contine in campul de destinatie textul de filtrare, 0 altfel
 */
int filtrare_destinatie(Oferta* o, char* text);

/*
 * functia ce determina daca o oferta indeplineste conditia de filtrare dupa tip
 * o - Oferta* (pointer catre adresa de memorie din heap unde este salvata oferta alocata dinamic)
 * text - char* (pointer catre un sir de caractere ce contine textul in functie de care are loc filtrarea)
 * returneaza 1 daca oferta contine in campul de tip textul de filtrare, 0 altfel
 */
int filtrare_tip(Oferta* o, char* text);

/*
 * functia ce determina daca o oferta indeplineste conditia de filtrare dupa pret
 * o - Oferta* (pointer catre adresa de memorie din heap unde este salvata oferta alocata dinamic)
 * text - char* (pointer catre un sir de caractere ce contine textul in functie de care are loc filtrarea)
 * returneaza 1 daca oferta contine in campul de pret valoarea reprezentata de textul de filtrare, 0 altfel
 */
int filtrare_pret(Oferta* o, char* pret);

/*
 * adaugat in laboratorul 5 de Paul
 * functia ce determina daca o oferta indeplineste conditia de filtrare dupa zi
 * o - Oferta* (pointer catre adresa de memorie din heap unde este salvata oferta alocata dinamic)
 * zi - char* (pointer catre un sir de caractere ce contine textul in functie de care are loc filtrarea)
 * returneaza 1 daca oferta contine in campul de pret valoarea reprezentata de textul de filtrare, 0 altfel
 */
int filtrare_zi(Oferta* o, char* zi);

/*
 * functia determina daca 2 oferte trebuie interschimbate pentru a se afla in ordinea dorita (aici: "<", in functie de pret)
 * o1, o2 - Oferta* (pointeri catre adresele de memorie din heap unde sunt salvate ofertele alocate dinamic)
 * returneaza 1 daca o1 > o2, 0 altfel
 */
int sortare_pret_cresc(Oferta* o1, Oferta* o2);

/*
 * functia determina daca 2 oferte trebuie interschimbate pentru a se afla in ordinea dorita (aici: ">", in functie de pret)
 * o1, o2 - Oferta* (pointeri catre adresele de memorie din heap unde sunt salvate ofertele alocate dinamic)
 * returneaza 1 daca o1 < o2, 0 altfel
 */
int sortare_pret_descresc(Oferta* o1, Oferta* o2);

/*
 * functia determina daca 2 oferte trebuie interschimbate pentru a se afla in ordinea dorita (aici: "<", in functie de destinatie)
 * o1, o2 - Oferta* (pointeri catre adresele de memorie din heap unde sunt salvate ofertele alocate dinamic)
 * returneaza 1 daca o1 > o2, 0 altfel
 */
int sortare_destinatie_cresc(Oferta* o1, Oferta* o2);

/*
 * functia determina daca 2 oferte trebuie interschimbate pentru a se afla in ordinea dorita (aici: ">", in functie de destinatie)
 * o1, o2 - Oferta* (pointeri catre adresele de memorie din heap unde sunt salvate ofertele alocate dinamic)
 * returneaza 1 daca o1 < o2, 0 altfel
 */
int sortare_destinatie_descresc(Oferta* o1, Oferta* o2);