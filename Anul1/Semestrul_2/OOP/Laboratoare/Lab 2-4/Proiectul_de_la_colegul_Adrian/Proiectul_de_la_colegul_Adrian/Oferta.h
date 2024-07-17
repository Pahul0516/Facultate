#pragma once

typedef struct
{
    int zi, luna, an;
}Data;

typedef struct
{
    char* tip;
    char* destinatie;
    Data data_plecare;
    double pret;
}Oferta;


/*
 * functie ce creeaza un obiect de tip Oferta
 * tip, destinatie - char*, nevide
 * zi, luna, an - integers, data trebuie sa fie valida
 * pret - double, pret >= 0
 * returneaza un pointer catre adresa de memorie din heap unde este salvata oferta alocata dinamic
 */
Oferta* creareOferta(char* tip, char* destinatie, int zi, int luna, int an, double pret);

/*
 * functie ce distruge o oferta alocata dinamic
 * oferta - Oferta* (pointer catre adresa de memorie din heap unde este salvata oferta alocata dinamic)
 * se elibereaza din memorie spatiul alocat ofertei
 */
void distrugereOferta(Oferta* oferta);

/*
 * functie ce valideaza o oferta alocata dinamic
 * oferta - Oferta* (pointer catre adresa de memorie din heap unde este salvata oferta alocata dinamic)
 * daca tipul e invalid, returneaza 1; daca destinatia e invalida, returneaza 2; daca pretul e invalid, returenaza 3; daca data de plecare e invalida, returneaza 4
 * daca oferta e valida, returneaza 0
 */
int validareOferta(Oferta* oferta);

/*
 * functie ce returneaza tipul unei oferte
 * oferta - Oferta* (pointer catre adresa de memorie din heap unde este salvata oferta alocata dinamic)
 */
char* get_tip(Oferta* oferta);

/*
 * functie ce returneaza destinatia unei oferte
 * oferta - Oferta* (pointer catre adresa de memorie din heap unde este salvata oferta alocata dinamic)
 */
char* get_destinatie(Oferta* oferta);

/*
 * functie ce returneaza pretul unei oferte
 * oferta - Oferta* (pointer catre adresa de memorie din heap unde este salvata oferta alocata dinamic)
 */
double get_pret(Oferta* oferta);

/*
 * functie ce returneaza ziua unei oferte
 * oferta - Oferta* (pointer catre adresa de memorie din heap unde este salvata oferta alocata dinamic)
 */
int get_zi(Oferta* oferta);

/*
 * functie ce returneaza luna unei oferte
 * oferta - Oferta* (pointer catre adresa de memorie din heap unde este salvata oferta alocata dinamic)
 */
int get_luna(Oferta* oferta);

/*
 * functie ce returneaza anul unei oferte
 * oferta - Oferta* (pointer catre adresa de memorie din heap unde este salvata oferta alocata dinamic)
 */
int get_an(Oferta* oferta);

/*
 * functie ce valideaza o data din calendar
 * data_plecare - struct ce contine ziua, luna si anul (struct Data)
 * returneaza 0 daca data e invalida; returneaza 1 daca e valida
 */
int validareData(Data data_plecare);

/*
 * functie ce creeaza o copie a ofertei, cu noi alocari de sine statatoare
 * oferta - Oferta* (pointer catre adresa de memorie din heap unde este salvata oferta alocata dinamic)
 * se returneaza un pointer catre noua locatie de memorie din heap unde a fost alocata copia ofertei
 */
Oferta* copy_oferta(Oferta* oferta);

