#include "MyList.h"
#include <stdlib.h>

ListaMea* creareLista(int cp)
{
    ListaMea* lista = (ListaMea*)malloc(sizeof(ListaMea));
    lista->lg = 0;
    lista->capacitate = cp;
    lista->elems = (Oferta** )malloc(cp * sizeof(Oferta*));
    return lista;
}

void distrugereLista(ListaMea* lista)
{
    free(lista->elems);
    free(lista);
}

Oferta* get(ListaMea* lista, int poz)
{
    return lista->elems[poz];
}

void set(ListaMea* lista, int poz, Oferta* o)
{
    lista->elems[poz] = o;
}

int size(ListaMea* lista)
{
    return lista->lg;
}


void resize(ListaMea* lista)
{
    int new_capacity = 2 * lista->capacitate;
    Oferta** new_list_of_elems = malloc(new_capacity * sizeof(Oferta*));
    for (int i = 0; i < size(lista); i ++)
        new_list_of_elems[i] = lista->elems[i];
    free(lista->elems);
    lista->elems = new_list_of_elems;
    lista->capacitate = new_capacity;
}

void adaugare(ListaMea* lista, ElemType el)
{
    if (lista->lg == lista->capacitate)
        resize(lista);
    lista->elems[lista->lg] = el;
    lista->lg ++;
}

int validarePozitie(ListaMea* lista, int poz)
{
    return poz < lista->lg;
}

void modificare(ListaMea* lista, Oferta* el, int poz)
{
    lista->elems[poz] = el;
}

void stergere(ListaMea* lista, int poz)
{
    for (int i = poz; i < size(lista) - 1; i ++)
        lista->elems[i] = lista->elems[i + 1];
    lista->lg --;
}

ListaMea* copiere_lista(ListaMea* lista)
{
    ListaMea* new_list = creareLista(lista->capacitate);
    for (int i = 0; i < lista->lg; i ++)
        adaugare(new_list, copy_oferta(lista->elems[i]));
    return new_list;
}

ListaMea* extragere_lista(ListaMea* lista)
{
    ListaMea* de_returnat= lista->elems[size(lista)-1];
    lista->lg = lista->lg - 1;
    return de_returnat;
}