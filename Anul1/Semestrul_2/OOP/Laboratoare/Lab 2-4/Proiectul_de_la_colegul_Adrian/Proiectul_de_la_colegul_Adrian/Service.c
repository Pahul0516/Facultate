#include "Service.h"
#include <stdio.h>

int adaugareOferta(ListaMea* lista, ListaMea* undo, char* tip, char* destinatie, int zi, int luna, int an, double pret)
{
    Oferta* oferta = creareOferta(tip, destinatie, zi, luna, an, pret);
    int error = validareOferta(oferta);
    if (error != 0)
    {
        distrugereOferta(oferta);
        return error;
    }
    adaugare(undo, copiere_lista(lista));
    adaugare(lista, oferta);
    return 0;
}

int modificareOferta(ListaMea* lista, ListaMea* undo, int id, char* tip, char* destinatie, int zi, int luna, int an, double pret)
{
    if (validarePozitie(lista, id) == 0)
        return 5;
    Oferta* oferta = creareOferta(tip, destinatie, zi, luna, an, pret);
    int error = validareOferta(oferta);
    if (error != 0)
    {
        distrugereOferta(oferta);
        return error;
    }
    adaugare(undo, copiere_lista(lista));
    distrugereOferta(get(lista, id));
    modificare(lista, oferta, id);
    return 0;
}

void distrugereTotala(ListaMea* lista)
{
    for(int i = 0; i < size(lista); i ++)
        distrugereOferta(get(lista, i));
    distrugereLista(lista);
}

int stergereOferta(ListaMea* lista, ListaMea* undo, int poz)
{
    if (validarePozitie(lista, poz) == 0)
        return 5;
    adaugare(undo, copiere_lista(lista));
    distrugereOferta(get(lista, poz));
    stergere(lista, poz);
    return 0;
}

ListaMea* sortareLista(ListaMea* lista, int(*conditieSortare)(Oferta*, Oferta*))
{
    ListaMea* new_list = copiere_lista(lista);
    for (int i = 0; i < size(new_list) - 1; i ++)
    {
        for (int j = i + 1; j < size(new_list); j ++)
            if ( conditieSortare( get(new_list, i), get(new_list, j) ) )
            {
                Oferta* aux = get(new_list, i);
                set(new_list, i, get(new_list, j));
                set(new_list, j, aux);
            }
    }
    return new_list;
}

ListaMea* filtrareLista(ListaMea* lista, int(*filtrare)(Oferta*, char*), char* sir)
{
    ListaMea* new_list = creareLista(2);
    for (int i = 0; i < size(lista); i ++)
        if ( filtrare( get(lista, i), sir ) )
            adaugare(new_list, copy_oferta(get(lista, i)));
    return new_list;
}

ListaMea* undo_lista(ListaMea* lista_init, ListaMea* undo)
{
    ListaMea* ultimul_elem = extragere_lista(undo);
    distrugereTotala(lista_init);
    lista_init = ultimul_elem;
    return lista_init;
}