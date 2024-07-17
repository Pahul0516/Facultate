#pragma once

#include "Oferta.h"

typedef void* ElemType;

typedef struct
{
    ElemType* elems;
    int lg;
    int capacitate;
}ListaMea;



/*
 * functie ce creeaza o lista alocata dinamic
 * cp - integer (capacitatea initiala a listei)
 * returneaza un pointer de tip ListaMea, catre inceputul listei alocate dinamic
 */
ListaMea* creareLista(int cp);

/*
 * functie ce dealoca memoria unei liste alocate dinamic
 * lista - ListaMea* ( pointer catre adresa de memorie din heap unde este salvata lista alocata dinamic )
 */
void distrugereLista(ListaMea* lista);

/*
 * functie ce determina obiectul din lista, aflat pe o anumita pozitie
 * lista - ListaMea* ( pointer catre adresa de memorie din heap unde este salvata lista alocata dinamic )
 * poz - integer (pozitia la care se afla obiectul dorit); poz >= 0; poz < size(len)
 * regturneaza un pointer catre adresa de memorie din heap unde se afla elementul aflat la pozitia 'poz'
 */
Oferta* get(ListaMea* lista, int poz);

/*
 * functie ce determina dimensiunea efectiva a listei alocate dinamic
 * lista - ListaMea* ( pointer catre adresa de memorie din heap unde este salvata lista alocata dinamic )
 * returneaza un integer, reprezentand lungimea efectiva a listei
 */
int size(ListaMea* lista);

/*
 * functie ce adauga in lista o noua oferta
 * lista - ListaMea* ( pointer catre adresa de memorie din heap unde este salvata lista alocata dinamic )
 * el - Oferta* (pointer catre adresa de memorie din heap unde este salvata oferta alocata dinamic)
 * oferta 'el' este adaugata la sfarsitul listei
 */
void adaugare(ListaMea* lista, ElemType el);

/*
 * functie ce determina daca o anumita pozitie din lista este valida/ accesibila
 * lista - ListaMea* ( pointer catre adresa de memorie din heap unde este salvata lista alocata dinamic )
 * poz - integer (pozitia la care se afla obiectul dorit)
 * returneaza 0 daca pozitia e invalida, 1 daca e valida
 */
int validarePozitie(ListaMea* lista, int poz);

/*
 * functie ce actualizeaza oferta aflata la o anumita pozitie in lista
 * lista - ListaMea* ( pointer catre adresa de memorie din heap unde este salvata lista alocata dinamic )
 * el - Oferta* (pointer catre adresa de memorie din heap unde este salvata oferta alocata dinamic)
 * poz - integer (pozitia la care se afla obiectul dorit)
 */
void modificare(ListaMea* lista, Oferta* el, int poz);

/*
 * functie ce sterge oferta aflata la o anumita pozitie in lista
 * lista - ListaMea* ( pointer catre adresa de memorie din heap unde este salvata lista alocata dinamic )
 * poz - integer (pozitia la care se afla obiectul dorit)
 */
void stergere(ListaMea* lista, int poz);

/*
 * functie ce creeaza o copie a unei liste alocate dinamic, cu noi alocari de sine statatoare
 * lista - ListaMea* ( pointer catre adresa de memorie din heap unde este salvata lista alocata dinamic )
 * se returneaza un pointer catre noua locatie de memorie din heap unde a fost alocata copia listei
 */
ListaMea* copiere_lista(ListaMea* lista);

/*
 * functie ce seteaza o oferta pe o anumita pozitie din lista
 * lista - ListaMea* ( pointer catre adresa de memorie din heap unde este salvata lista alocata dinamic )
 * poz - integer (pozitia la care va avea loc atribuirea)
 * o - Oferta* (pointer catre adresa de memorie din heap unde este salvata oferta alocata dinamic)
 */
void set(ListaMea* lista, int poz, Oferta* o);


ListaMea* extragere_lista(ListaMea* lista);

