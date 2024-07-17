#include "tests.h"
#include "MyList.h"
#include "assert.h"
#include "string.h"
#include "Service.h"
#include "math.h"
#include "utils.h"

void testCreareOferta();
void testValidare();
void testLista();
void testAdaugareService();
void testModificare();
void testModificareService();
void testStergere();
void testStergereService();
void testValidareDataOferta();
void testCopiereOferta();
void testCopiereLista();
void testSortareLista();
void testFiltrareDestinatie();
void testFiltrareTip();
void testFiltrarePret();
void testFiltrareZi();
void testFiltrareLista();
void testSortarePretCresc();
void testSortarePretDescresc();
void testSortareDestinatieCresc();
void testSortareDestinatieDescresc();
void testExtragerLista();
void testUndo();

void allTests()
{
    testCreareOferta();
    testValidare();
    testLista();
    testAdaugareService();
    testModificare();
    testModificareService();
    testStergere();
    testStergereService();
    testValidareDataOferta();

    testCopiereOferta();
    testCopiereLista();
    testSortareLista();
    testFiltrareDestinatie();
    testFiltrareTip();
    testFiltrarePret();
    testFiltrareZi();
    testFiltrareLista();

    testSortarePretCresc();
    testSortarePretDescresc();
    testSortareDestinatieCresc();
    testSortareDestinatieDescresc();
    testExtragerLista();
    testUndo();

}

void testCreareOferta()
{

    Oferta* o1 = creareOferta("munte", "busteni", 12, 12, 2024, 1200.50);
    assert (strcmp(get_tip(o1), "munte") == 0);
    assert (strcmp(get_destinatie(o1), "busteni") == 0);
    assert (get_zi(o1) == 12 && get_luna(o1) == 12 && get_an(o1) == 2024);
    assert (get_pret(o1) == 1200.50);
    distrugereOferta(o1);
}

void testValidare()
{
    Oferta* oferta = creareOferta("munte", "busteni", 13, 13, 2022, 140);
    assert (validareOferta(oferta) == 4);
    distrugereOferta(oferta);

    oferta = creareOferta("munte", "", 13, 11, 2022, 140);
    assert (validareOferta(oferta) == 2);
    distrugereOferta(oferta);

    oferta = creareOferta("", "busteni", 13, 3, 2022, 140);
    assert (validareOferta(oferta) == 1);
    distrugereOferta(oferta);

    oferta = creareOferta("munte", "busteni", 13, 11, 2022, -12);
    assert (validareOferta(oferta) == 3);
    distrugereOferta(oferta);
}

void testLista()
{
    ListaMea* lista = creareLista(2);
    Oferta* o1 = creareOferta("munte", "busteni", 13, 11, 2022, 120.12);
    Oferta* o2 = creareOferta("mare", "eforie nord", 1, 7, 2021, 1200.54);
    Oferta* o3 = creareOferta("city break", "praga", 20, 5, 2011, 120.33);
    adaugare(lista, o1);
    adaugare(lista, o2);
    assert (size(lista) == 2);
    adaugare(lista, o3);
    assert (size(lista) == 3);
    assert (get(lista, 2) == o3);
    assert (get(lista, 0) == o1);

    distrugereOferta(o1);
    distrugereOferta(o2);
    distrugereOferta(o3);

    distrugereLista(lista);
}

void testAdaugareService()
{
    ListaMea* lista = creareLista(2);
    ListaMea* undo = creareLista(2);
    assert (adaugareOferta(lista, undo, "munte", "busteni", 13, 11, 2022, 120.12) == 0);
    assert (adaugareOferta(lista, undo, "mare", "eforie nord", 1, 7, 2021, 1200.54) == 0 );
    assert (size(lista) == 2);
    assert (adaugareOferta(lista, undo, "mare", "", 1, 7, 2021, 1200.54) == 2);
    assert (adaugareOferta(lista, undo, "", "", 1, 7, 2021, 1200.54) == 1);
    assert (adaugareOferta(lista, undo, "aaa", "dd", 1, 17, 2021, 1200.54) == 4);
    assert (adaugareOferta(lista, undo, "city break", "praga", 20, 5, 2011, 120.33) == 0);
    assert ( fabs( get_pret(get(lista, 2)) - 120.33) < 0.0001 );
    distrugereTotala(lista);
    if (undo->lg != 0)
    {
        for (int i = 0; i < undo->lg; i++)
            distrugereTotala(undo->elems[i]);
    }
    distrugereLista(undo);
}

void testModificare()
{
    ListaMea* lista = creareLista(2);
    Oferta* o1 = creareOferta("munte", "busteni", 13, 11, 2022, 120.12);
    Oferta* o2 = creareOferta("mare", "eforie nord", 1, 7, 2021, 1200.54);
    Oferta* o3 = creareOferta("city break", "praga", 20, 5, 2011, 120.33);
    adaugare(lista, o1);
    adaugare(lista, o2);
    adaugare(lista, o3);
    Oferta* o4 = creareOferta("city break", "varsovia", 30, 4, 2010, 120.33);
    modificare(lista, o4, 2 );
    assert ( strcmp(get_destinatie( get(lista, 2) ), "varsovia") == 0 );
    assert ( strcmp(get_tip( get(lista, 2) ), "city break") == 0 );
    assert ( get_zi(get(lista, 2)) == 30 && get_luna(get(lista, 2)) == 4 );

    distrugereOferta(o1);
    distrugereOferta(o2);
    distrugereOferta(o3);
    distrugereOferta(o4);

    distrugereLista(lista);
}

void testModificareService()
{
    ListaMea* lista = creareLista(2);
    ListaMea* undo = creareLista(2);
    adaugareOferta(lista, undo, "munte", "busteni", 13, 11, 2022, 120.12);
    adaugareOferta(lista, undo, "mare", "eforie nord", 1, 7, 2021, 1200.54);
    adaugareOferta(lista, undo, "city break", "praga", 20, 5, 2011, 120.33);

    assert (modificareOferta(lista, undo, 1, "mare", "mamaia", 2, 3, 2020, 134.23) == 0);
    assert (modificareOferta(lista, undo, 6, "mare", "mamaia", 2, 3, 2020, 134.23) == 5);
    assert (modificareOferta(lista, undo, 0, "mare", "", 2, 3, 2020, 134.23) == 2);
    assert (strcmp(get_destinatie(get(lista, 1)), "mamaia") == 0 );
    assert (get_zi(get(lista, 1)) == 2 && get_luna(get(lista, 1)) == 3);
    assert (size(lista) == 3);

    distrugereTotala(lista);
    if (undo->lg != 0)
    {
        for (int i = 0; i < undo->lg; i++)
            distrugereTotala(undo->elems[i]);
    }
    distrugereLista(undo);
}

void testStergere()
{
    ListaMea* lista = creareLista(2);
    Oferta* o1 = creareOferta("munte", "busteni", 13, 11, 2022, 120.12);
    Oferta* o2 = creareOferta("mare", "eforie nord", 1, 7, 2021, 1200.54);
    Oferta* o3 = creareOferta("city break", "praga", 20, 5, 2011, 120.33);
    adaugare(lista, o1);
    adaugare(lista, o2);
    adaugare(lista, o3);

    assert (size(lista) == 3);
    stergere(lista, 1);
    assert (size(lista) == 2);
    assert (strcmp(get_tip(get(lista, 1)), "city break") == 0);
    stergere(lista, 0);
    assert (size(lista) == 1);
    assert (strcmp(get_destinatie(get(lista, 0)), "praga") == 0);

    distrugereOferta(o1);
    distrugereOferta(o2);
    distrugereOferta(o3);

    distrugereLista(lista);
}

void testStergereService()
{
    ListaMea* lista = creareLista(2);
    ListaMea* undo = creareLista(2);
    adaugareOferta(lista, undo, "munte", "busteni", 13, 11, 2022, 120.12);
    adaugareOferta(lista, undo, "mare", "eforie nord", 1, 7, 2021, 1200.54);
    adaugareOferta(lista, undo, "city break", "praga", 20, 5, 2011, 120.33);

    assert(stergereOferta(lista, undo, 4) == 5);
    assert(stergereOferta(lista, undo, 1) == 0);
    assert(stergereOferta(lista, undo, 2) == 5);
    assert(strcmp(get_tip(get(lista, 1)), "city break") == 0);
    assert(fabs(120.33 - get_pret(get(lista, 1))) < 0.00001);
    assert(stergereOferta(lista, undo, 0) == 0);
    assert(get_an(get(lista, 0)) == 2011);

    distrugereTotala(lista);
    if (undo->lg != 0)
    {
        for (int i = 0; i < undo->lg; i++)
            distrugereTotala(undo->elems[i]);
    }
    distrugereLista(undo);
}


void testValidareDataOferta()
{
    Data data;
    data.zi = 12, data.luna = 12, data.an = 2020;
    assert ( validareData(data) == 1 );
    data.zi = -3, data.luna = 12, data.an = 2020;
    assert (validareData(data) == 0 );
    data.zi = 12, data.luna = 15, data.an = 2020;
    assert ( validareData(data) == 0 );
    data.zi = 31, data.luna = 4, data.an = 2020;
    assert ( validareData(data) == 0 );
    data.zi = 31, data.luna = 2, data.an = 2020;
    assert ( validareData(data) == 0 );
    data.zi = 29, data.luna = 2, data.an = 2019;
    assert ( validareData(data) == 0 );

}

void testCopiereOferta()
{
    Oferta* o = creareOferta("mare", "constanta", 12, 12, 2022, 12.33);
    Oferta* o_new = copy_oferta(o);
    assert (strcmp(o->destinatie, o_new->destinatie) == 0);
    assert (strcmp(o->tip, o_new->tip) == 0);
    assert (o->data_plecare.an == o_new->data_plecare.an && o->data_plecare.luna == o_new->data_plecare.luna && o->data_plecare.zi == o_new->data_plecare.zi);
    assert (fabs(o->pret - o_new->pret) < 0.0001);

    distrugereOferta(o);
    distrugereOferta(o_new);
}

void testCopiereLista()
{
    /*
    ListaMea* list = creareLista(4);
    ListaMea* undo = creareLista(4);
    adaugare(list, undo, creareOferta("mare", "constanta", 12, 12, 2022, 12.33));
    adaugare(list, undo, creareOferta("munte", "predeal", 17, 3, 2009, 99.233));
    ListaMea* new_list = copiere_lista(list);
    assert (new_list->capacitate == list->capacitate && new_list->lg == list->lg);
    assert (strcmp(new_list->elems[0]->destinatie, list->elems[0]->destinatie) == 0 );
    assert (strcmp(new_list->elems[1]->tip, list->elems[1]->tip) == 0);
    assert (new_list->elems[0]->data_plecare.an == list->elems[0]->data_plecare.an);
    assert (fabs(new_list->elems[0]->pret - list->elems[0]->pret) < 0.00001);

    distrugereTotala(list);
    distrugereTotala(new_list);
    */
}

void testSortareLista()
{
    ListaMea* lista = creareLista(2);
    Oferta* o1 = creareOferta("mare", "predeal", 1, 1, 2020, 12.33);
    Oferta* o2 = creareOferta("mare", "eforie", 2, 2, 2020, 12);
    Oferta* o3 = creareOferta("mare", "eforie", 2, 2, 2020, 9);
    Oferta* o4 = creareOferta("mare", "eforie", 2, 2, 2020, 15);
    Oferta* o5 = creareOferta("mare", "mangalia", 2, 2, 2020, 12);
    Oferta* o6 = creareOferta("mare", "aaa", 2, 2, 2020, 12);
    adaugare(lista, o1), adaugare(lista, o2), adaugare(lista, o3), adaugare(lista, o4), adaugare(lista, o5), adaugare(lista, o6);

    ListaMea* new_list = sortareLista(lista, sortare_pret_cresc);
    assert ( fabs( get_pret(get(new_list, 0)) - 9  ) < 0.0001 );
    assert ( fabs( get_pret(get(new_list, 1)) - 12  ) < 0.0001 );
    assert ( fabs( get_pret(get(new_list, 2)) - 12  ) < 0.0001 );
    assert ( fabs( get_pret(get(new_list, 3)) - 12  ) < 0.0001 );
    assert ( fabs( get_pret(get(new_list, 4)) - 12.33  ) < 0.0001 );
    assert ( fabs( get_pret(get(new_list, 5)) - 15  ) < 0.0001 );
    distrugereTotala(new_list);

    new_list = sortareLista(lista, sortare_pret_descresc);
    assert ( fabs( get_pret(get(new_list, 5)) - 9  ) < 0.0001 );
    assert ( fabs( get_pret(get(new_list, 4)) - 12  ) < 0.0001 );
    assert ( fabs( get_pret(get(new_list, 3)) - 12  ) < 0.0001 );
    assert ( fabs( get_pret(get(new_list, 2)) - 12  ) < 0.0001 );
    assert ( fabs( get_pret(get(new_list, 1)) - 12.33  ) < 0.0001 );
    assert ( fabs( get_pret(get(new_list, 0)) - 15  ) < 0.0001 );
    distrugereTotala(new_list);

    new_list = sortareLista(lista, sortare_destinatie_cresc);
    assert ( strcmp(get_destinatie(get(new_list, 0) ), "aaa") == 0 );
    assert ( strcmp(get_destinatie(get(new_list, 1) ), "eforie") == 0 );
    assert ( strcmp(get_destinatie(get(new_list, 2) ), "eforie") == 0 );
    assert ( strcmp(get_destinatie(get(new_list, 3) ), "eforie") == 0 );
    assert ( strcmp(get_destinatie(get(new_list, 4) ), "mangalia") == 0 );
    assert ( strcmp(get_destinatie(get(new_list, 5) ), "predeal") == 0 );
    distrugereTotala(new_list);

    new_list = sortareLista(lista, sortare_destinatie_descresc);
    assert ( strcmp(get_destinatie(get(new_list, 5) ), "aaa") == 0 );
    assert ( strcmp(get_destinatie(get(new_list, 4) ), "eforie") == 0 );
    assert ( strcmp(get_destinatie(get(new_list, 3) ), "eforie") == 0 );
    assert ( strcmp(get_destinatie(get(new_list, 2) ), "eforie") == 0 );
    assert ( strcmp(get_destinatie(get(new_list, 1) ), "mangalia") == 0 );
    assert ( strcmp(get_destinatie(get(new_list, 0) ), "predeal") == 0 );
    distrugereTotala(new_list);

    distrugereTotala(lista);
}

void testFiltrareDestinatie()
{
    Oferta* o = creareOferta("mare", "eforie", 2, 3, 2020, 12.34);
    assert (filtrare_destinatie(o, "eforie") == 1);
    assert (filtrare_destinatie(o, "efori") == 0);
    distrugereOferta(o);

}
void testFiltrareTip()
{
    Oferta* o = creareOferta("mare", "eforie", 2, 3, 2020, 12.34);
    assert (filtrare_tip(o, "mare") == 1);
    assert (filtrare_tip(o, "mar") == 0);
    distrugereOferta(o);
}

void testFiltrarePret()
{
    Oferta* o = creareOferta("mare", "eforie", 2, 3, 2020, 12.34);
    assert (filtrare_pret(o, "12.34") == 1);
    assert (filtrare_pret(o, "12.33") == 0);
    distrugereOferta(o);
}

void testFiltrareZi()
{
    Oferta* o = creareOferta("mare", "eforie", 2, 3, 2020, 12.34);
    assert(filtrare_zi(o, "2") == 1);
    assert(filtrare_zi(o, "12") == 0);
    distrugereOferta(o);
}


void testFiltrareLista()
{
    ListaMea* lista = creareLista(2);
    Oferta* o1 = creareOferta("mare", "predeal", 1, 1, 2021, 12.33);
    Oferta* o2 = creareOferta("munte", "eforie", 2, 2, 2020, 12);
    Oferta* o3 = creareOferta("mare", "eforie", 2, 2, 2019, 9);
    Oferta* o4 = creareOferta("munte", "eforie", 2, 2, 2018, 15);
    Oferta* o5 = creareOferta("mare2", "mangalia", 2, 2, 2017, 12);
    Oferta* o6 = creareOferta("mare1", "aaa", 2, 2, 2016, 12);
    adaugare(lista, o1), adaugare(lista, o2), adaugare(lista, o3), adaugare(lista, o4), adaugare(lista, o5), adaugare(lista, o6);
    ListaMea* filtred_list;
    filtred_list = filtrareLista(lista, filtrare_destinatie, "eforie");
    assert (size(filtred_list) == 3);
    assert ( fabs(get_pret(get(filtred_list, 1)) - 9) < 0.0001 );
    assert ( fabs(get_pret(get(filtred_list, 2)) - 15) < 0.0001 );
    distrugereTotala(filtred_list);

    filtred_list = filtrareLista(lista, filtrare_tip, "mare");
    assert (size(filtred_list) == 2);
    assert ( fabs(get_pret(get(filtred_list, 0)) - 12.33) < 0.0001 );
    assert ( fabs(get_pret(get(filtred_list, 1)) - 9) < 0.0001 );
    distrugereTotala(filtred_list);

    filtred_list = filtrareLista(lista, filtrare_pret, "12");
    assert (size(filtred_list) == 3);
    assert (get_an(get(filtred_list, 0)) == 2020);
    assert (get_an(get(filtred_list, 1)) == 2017);
    assert (get_an(get(filtred_list, 2)) == 2016);
    distrugereTotala(filtred_list);

    distrugereTotala(lista);
}

void testSortarePretCresc()
{
    Oferta* o1 = creareOferta("mare", "constanta", 12, 12, 2020, 123.334);
    Oferta* o2 = creareOferta("mare", "constanta", 12, 12, 2020, 96.35);
    assert ( sortare_pret_cresc(o1, o2) == 1 );
    distrugereOferta(o1);
    distrugereOferta(o2);
    o1 = creareOferta("mare", "constanta", 12, 12, 2020, 123.334);
    o2 = creareOferta("mare", "constanta", 12, 12, 2020, 196.35);
    assert ( sortare_pret_cresc(o1, o2) == 0 );
    distrugereOferta(o1);
    distrugereOferta(o2);
}

void testSortarePretDescresc()
{
    Oferta* o1 = creareOferta("mare", "constanta", 12, 12, 2020, 123.334);
    Oferta* o2 = creareOferta("mare", "constanta", 12, 12, 2020, 96.35);
    assert ( sortare_pret_descresc(o1, o2) == 0 );
    distrugereOferta(o1);
    distrugereOferta(o2);
    o1 = creareOferta("mare", "constanta", 12, 12, 2020, 123.334);
    o2 = creareOferta("mare", "constanta", 12, 12, 2020, 196.35);
    assert ( sortare_pret_descresc(o1, o2) == 1 );
    distrugereOferta(o1);
    distrugereOferta(o2);
}

void testSortareDestinatieCresc()
{
    Oferta* o1 = creareOferta("mare", "constanta", 12, 12, 2020, 123.334);
    Oferta* o2 = creareOferta("munte", "sinaia", 12, 12, 2020, 96.35);
    assert ( sortare_destinatie_cresc(o1, o2) == 0 );
    distrugereOferta(o1);
    distrugereOferta(o2);
    o1 = creareOferta("mare", "sinaia", 12, 12, 2020, 123.334);
    o2 = creareOferta("munte", "constanta", 12, 12, 2020, 196.35);
    assert ( sortare_destinatie_cresc(o1, o2) == 1 );
    distrugereOferta(o1);
    distrugereOferta(o2);
}

void testSortareDestinatieDescresc()
{
    Oferta* o1 = creareOferta("mare", "constanta", 12, 12, 2020, 123.334);
    Oferta* o2 = creareOferta("munte", "sinaia", 12, 12, 2020, 96.35);
    assert ( sortare_destinatie_descresc(o1, o2) == 1 );
    distrugereOferta(o1);
    distrugereOferta(o2);
    o1 = creareOferta("mare", "sinaia", 12, 12, 2020, 123.334);
    o2 = creareOferta("munte", "constanta", 12, 12, 2020, 96.35);
    assert ( sortare_destinatie_descresc(o1, o2) == 0 );
    distrugereOferta(o1);
    distrugereOferta(o2);
}

void testExtragerLista()
{
    ListaMea* lista_de_Liste = creareLista(2);
    ListaMea* lista1 = creareLista(2);
    ListaMea* lista2 = creareLista(2);
    Oferta* o1 = creareOferta("mare", "constanta", 12, 12, 2020, 123.334);
    Oferta* o2 = creareOferta("munte", "sinaia", 12, 12, 2020, 96.35);
    adaugare(lista1, o1);
    adaugare(lista1, o2);
    adaugare(lista_de_Liste, lista1);
    adaugare(lista_de_Liste, lista2);
    extragere_lista(lista_de_Liste);
    assert(lista_de_Liste->lg == 1);
    distrugereTotala(lista2);
    for (int i = 0; i < lista_de_Liste->lg; i++)
    {
        distrugereTotala(lista_de_Liste->elems[i]);
    }
    distrugereLista(lista_de_Liste);
}

void testUndo()
{
    ListaMea* lista_de_Liste = creareLista(2);
    ListaMea* lista = creareLista(2);
    Oferta* o1 = creareOferta("mare", "constanta", 12, 12, 2020, 123.334);
    Oferta* o2 = creareOferta("munte", "sinaia", 12, 12, 2020, 96.35);
    adaugare(lista, o1);
    adaugare(lista, o2);
    adaugare(lista_de_Liste, lista);
    ListaMea* ce_se_returneaza = creareLista(2);
    ce_se_returneaza = undo_lista(ce_se_returneaza, lista_de_Liste);
    assert(ce_se_returneaza->lg == 2);
    distrugereTotala(ce_se_returneaza);
    distrugereLista(lista_de_Liste);
}