#pragma once

#include "MyList.h"

/*
 * functie ce creeaza o oferta pornind de la datele obtinute de la utilizator si o adauga in lista
 * lista - ListaMea* ( pointer catre adresa de memorie din heap unde este salvata lista alocata dinamic )
 * tip, destinatie - char*, nevide
 * zi, luna, an - integers, data trebuie sa fie valida
 * pret - double, pret >= 0
 * daca oferta e adaugata cu succes, se returneaza 0; altfel, se returneaza un numar nenul
 */
int adaugareOferta(ListaMea* lista, ListaMea* undo, char* tip, char* destinatie, int zi, int luna, int an, double pret);

/*
 * functie ce dealoca fiecare obiect din lista, respectiv lista insasi
 * lista - ListaMea* ( pointer catre adresa de memorie din heap unde este salvata lista alocata dinamic )
 */
void distrugereTotala(ListaMea* lista);


/*
 * functie ce inlocuieste o oferta aflata pe o anumita pozitie in lista, cu o noua oferta, creata cu ajutorul datelor primite de la utilizator
 * lista - ListaMea* ( pointer catre adresa de memorie din heap unde este salvata lista alocata dinamic )
 * id - integer (pozitia la care se afla oferta care se doreste a fi actualizata); id >= 0; id < size(lista)
 * tip, destinatie - char*, nevide
 * zi, luna, an - integers, data trebuie sa fie valida
 * pret - double, pret >= 0
 * daca actualizarea are loc fara erori, se returneaza 0; altfel, se returneaza un numar nenul
 */
int modificareOferta(ListaMea* lista, ListaMea* undo, int id, char* tip, char* destinatie, int zi, int luna, int an, double pret);

/*
 * functie ce sterge oferta aflata la o anumita pozitie in lista
 * lista - ListaMea* ( pointer catre adresa de memorie din heap unde este salvata lista alocata dinamic )
 * poz - integer (pozitia la care se afla oferta care se doreste a fi stearsa); id >= 0; id < size(lista)
 * daca stergerea are loc cu succes se returneaza 0; altfel, daca pozitia nu e valida in lista, se returneaza 5
 */
int stergereOferta(ListaMea* lista, ListaMea* undo, int poz);

/*
 * functie ce creeaza o noua lista sortata dupa un anumit criteriu
 * lista - ListaMea* ( pointer catre adresa de memorie din heap unde este salvata lista alocata dinamic )
 * conditieSortare - pointer catre o functie ce primeste ca parametrii 2 adrese de memorie care pointeaza spre 2 oferte si returneaza 1 daca trebuie sa aiba loc interschimbarea, 0 altfel
 * se returneaza un pointer catre noua lista alocata dinamic, sortata pe baza functiei primite ca parametru
 */
ListaMea* sortareLista(ListaMea* lista, int(*conditieSortare)(Oferta*, Oferta*));

/*
 * functie ce creeaza o noua lista ce contine ofertele cu o anumita proprietate din lista initiala
 * lista - ListaMea* ( pointer catre adresa de memorie din heap unde este salvata lista alocata dinamic )
 * filtrare - pointer catre o functie ce primeste ca parametrii o adresa de memorie care pointeaza spre o oferta si un pointer de tip char, ce contine sirul pe baza caruia are loc filtrarea; aceasta functie returneaza 1 daca oferta respecta conditia impusa de filtru, 0 altfel
 * sir - pointer catre un sir de caractere pe baza caruia are loc filtrarea
 * se returneaza un pointer care noua lista alocata dinamic, ce contine ofertele din prima lista trecute printr-un proces de filtrare
 */
ListaMea* filtrareLista(ListaMea* lista, int(*filtrare)(Oferta*, char*), char* sir);


ListaMea* undo_lista(ListaMea* lista_init, ListaMea* undo);
