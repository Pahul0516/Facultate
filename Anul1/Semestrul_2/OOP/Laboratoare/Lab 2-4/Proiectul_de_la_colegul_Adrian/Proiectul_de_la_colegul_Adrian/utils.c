//
// Created by Adi on 3/17/2024.
//
#include "utils.h"
#include <string.h>
#include <math.h>
#include <stdlib.h>

int filtrare_destinatie(Oferta* o, char* text)
{
    return ( strcmp(get_destinatie(o), text ) == 0 );
}

int filtrare_tip(Oferta* o, char* text)
{
    return ( strcmp(get_tip(o), text) == 0 );
}

int filtrare_pret(Oferta* o, char* pret)
{
    char *ptr;
    double val = strtod(pret, &ptr);
    return ( fabs(o->pret - val) < 0.0001 );
}

int filtrare_zi(Oferta* o, char* zi)
{
    int val = atoi(zi);
    return (get_zi(o) == val);
}

int sortare_pret_cresc(Oferta* o1, Oferta* o2)
{
    return get_pret(o1) > get_pret(o2);
}

int sortare_pret_descresc(Oferta* o1, Oferta* o2)
{
    return get_pret(o1) < get_pret(o2);
}

int sortare_destinatie_cresc(Oferta* o1, Oferta* o2)
{
    return strcmp( get_destinatie(o1), get_destinatie(o2) ) > 0;
}

int sortare_destinatie_descresc(Oferta* o1, Oferta* o2)
{
    return strcmp( get_destinatie(o1), get_destinatie(o2) ) < 0;
}