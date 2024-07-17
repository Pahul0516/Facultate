#define _CRT_SECURE_NO_WARNINGS
#include "Oferta.h"
#include <string.h>
#include <stdlib.h>

Oferta* creareOferta(char* tip, char* destinatie, int zi, int luna, int an, double pret)
{
    Oferta* o = (Oferta*)malloc(sizeof(Oferta));
    o->tip = malloc(strlen(tip) + 1);
    o->destinatie = malloc(strlen(destinatie) + 1);
    strcpy(o->tip, tip);
    strcpy(o->destinatie, destinatie);
    o->data_plecare.zi = zi, o->data_plecare.luna = luna, o->data_plecare.an = an;
    o->pret = pret;
    return o;
}

void distrugereOferta(Oferta* oferta)
{
    free(oferta->tip);
    free(oferta->destinatie);
    free(oferta);
}

int validareData(Data data_plecare)
{
    if (data_plecare.zi <= 0 || data_plecare.zi >= 32)
        return 0;
    if (data_plecare.luna <= 0 || data_plecare.luna >= 13)
        return 0;
    if (data_plecare.luna == 4 || data_plecare.luna == 6 || data_plecare.luna == 9 || data_plecare.luna == 11)
        if (data_plecare.zi == 31)
            return 0;
    if (data_plecare.luna == 2)
    {
        /// conditie an bisect
        if (data_plecare.an % 400 == 0 || (data_plecare.an % 4 == 0 && data_plecare.an % 100 != 0))
        {
            /// e an bisect
            if (data_plecare.zi >= 30)
                return 0;
        }
        else if (data_plecare.zi >= 29)
                return 0;
    }
    return 1;
}

int validareOferta(Oferta* oferta)
{
    if (strlen(oferta->tip) == 0)
        return 1;
    if (strlen(oferta->destinatie) == 0)
        return 2;
    if (oferta->pret < 0)
        return 3;
    if (validareData(oferta->data_plecare) == 0)
        return 4;
    return 0;
}

char* get_tip(Oferta* oferta)
{
    return oferta->tip;
}

char* get_destinatie(Oferta* oferta)
{
    return oferta->destinatie;
}

double get_pret(Oferta* oferta)
{
    return oferta->pret;
}

int get_zi(Oferta* oferta)
{
    return oferta->data_plecare.zi;
}

int get_luna(Oferta* oferta)
{
    return oferta->data_plecare.luna;
}

int get_an(Oferta* oferta)
{
    return oferta->data_plecare.an;
}

Oferta* copy_oferta(Oferta* oferta)
{
    Oferta* oferta_new = (Oferta*)malloc(sizeof(Oferta));
    oferta_new->tip = (char*)malloc(strlen(oferta->tip) + 1);
    oferta_new->destinatie = (char*)malloc(strlen(oferta->destinatie) + 1);
    oferta_new->data_plecare = oferta->data_plecare;
    strcpy(oferta_new->tip, oferta->tip);
    strcpy(oferta_new->destinatie, oferta->destinatie);
    oferta_new->pret = oferta->pret;
    return oferta_new;
}