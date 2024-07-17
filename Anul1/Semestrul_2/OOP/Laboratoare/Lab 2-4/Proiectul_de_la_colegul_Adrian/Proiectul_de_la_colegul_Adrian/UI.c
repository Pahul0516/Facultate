#define _CRT_SECURE_NO_WARNINGS
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_RESET   "\x1b[0m"
#include "UI.h"
#include <stdio.h>
#include "Service.h"
#include "string.h"
#include "utils.h"

void menu()
{
    printf("MENU\n");
    printf("1. Adaugare oferta\n");
    printf("2. Actualizare oferta\n");
    printf("3. Stergere oferta\n");
    printf("4. Sortare oferte\n");
    printf("5. Filtrare oferte\n");
    printf("6. Undo\n");
    printf("7. Iesire\n");
}

void afisareOferte(ListaMea* lista)
{
    if (size(lista) == 0)
    {
        printf("Nicio oferta inregistrata!\n");
        return;
    }
    for (int i = 0; i < size(lista); i ++)
    {
        Oferta* oferta = get(lista, i);
        printf("%d. Tip: %s, Destinatie: %s, Zi: %d, Luna: %d, An: %d, Pret: %.4f\n", i, get_tip(oferta), get_destinatie(oferta), get_zi(oferta), get_luna(oferta), get_an(oferta), get_pret(oferta));
    }
}

void adaugare_ui(ListaMea* lista, ListaMea* undo)
{
    char tip[200], destinatie[200], aux;
    int zi, luna, an;
    double pret;
    scanf("%c", &aux);
    printf("Tip: ");
    fgets(tip, 200, stdin);
    tip[strlen(tip) - 1] = '\0'; /// eliminare new line
    printf("Destinatie: ");
    fgets(destinatie, 200, stdin);
    destinatie[strlen(destinatie) - 1] = '\0'; /// eliminare new line
    printf("Zi: ");
    scanf("%d", &zi);
    printf("Luna: ");
    scanf("%d", &luna);
    printf("An: ");
    scanf("%d", &an);
    printf("Pret: ");
    scanf("%lf", &pret);

    int error = adaugareOferta(lista, undo, tip, destinatie, zi, luna, an, pret);
    if (error == 0) printf(ANSI_COLOR_GREEN"Adaugare cu succes!\n"ANSI_COLOR_RESET);
    else if (error == 1) printf(ANSI_COLOR_RED"Tip invalid!\n"ANSI_COLOR_RESET);
    else if (error == 2) printf(ANSI_COLOR_RED"Destinatie invalida!\n"ANSI_COLOR_RESET);
    else if (error == 3) printf(ANSI_COLOR_RED"Pret invalid!\n"ANSI_COLOR_RESET);
    else if (error == 4) printf(ANSI_COLOR_RED"Data invalida!\n"ANSI_COLOR_RESET);
}

void modificare_ui(ListaMea* lista, ListaMea* undo)
{
    int id;
    char tip[200], destinatie[200], aux;
    int zi, luna, an;
    double pret;
    printf("ID: ");
    scanf("%d", &id);
    scanf("%c", &aux);
    printf("Tip: ");
    fgets(tip, 200, stdin);
    tip[strlen(tip) - 1] = '\0'; /// eliminare new line
    printf("Destinatie: ");
    fgets(destinatie, 200, stdin);
    destinatie[strlen(destinatie) - 1] = '\0'; /// eliminare new line
    printf("Zi: ");
    scanf("%d", &zi);
    printf("Luna: ");
    scanf("%d", &luna);
    printf("An: ");
    scanf("%d", &an);
    printf("Pret: ");
    scanf("%lf", &pret);

    int error = modificareOferta(lista, undo, id, tip, destinatie, zi, luna, an, pret);
    if (error == 0) printf(ANSI_COLOR_GREEN"Modificare cu succes!\n"ANSI_COLOR_RESET);
    else if (error == 1) printf(ANSI_COLOR_RED"Tip invalid!\n"ANSI_COLOR_RESET);
    else if (error == 2) printf(ANSI_COLOR_RED"Destinatie invalida!\n"ANSI_COLOR_RESET);
    else if (error == 3) printf(ANSI_COLOR_RED"Pret invalid!\n"ANSI_COLOR_RESET);
    else if (error == 4) printf(ANSI_COLOR_RED"Data invalida!\n"ANSI_COLOR_RESET);
    else if (error == 5) printf(ANSI_COLOR_RED"ID invalid!\n"ANSI_COLOR_RESET);
}

void stergere_ui(ListaMea* lista, ListaMea* undo)
{
    int id;
    printf("ID: ");
    scanf("%d", &id);
    int error = stergereOferta(lista, undo, id);
    if (error == 5) printf("ID invalid!\n");
    else printf(ANSI_COLOR_GREEN"Stergere cu succes!\n"ANSI_COLOR_RESET);
}

void sortare_ui(ListaMea* lista) {
    printf("Introduceti cifra corespunzatoare tipului de ordonare dorit:\n");
    printf("1. dupa pret\n");
    printf("2. dupa destinatie\n");
    int choice;
    scanf("%d", &choice);

    if (choice != 1 && choice != 2)
    {
        printf(ANSI_COLOR_RED"Nu ai introdus o cifra valida!\n"ANSI_COLOR_RESET);
        return;
    }

    printf("Introduceti cifra corespunzatoare sortarii dorite:\n");
    printf("1. crescator\n");
    printf("2. descrescator\n");
    int sortat;
    scanf("%d", &sortat);

    if (sortat != 1 && sortat != 2)
    {
        printf(ANSI_COLOR_RED"Nu ai introdus o cifra valida!\n"ANSI_COLOR_RESET);
        return;
    }

    ListaMea* sorted_list; // = sortareLista(lista, sortat);
    if (sortat == 1)
    {
        if (choice == 1)
            sorted_list = sortareLista(lista, sortare_pret_cresc);
        else
            sorted_list = sortareLista(lista, sortare_destinatie_cresc);
    }
    else
    {
        if (choice == 1)
            sorted_list = sortareLista(lista, sortare_pret_descresc);
        else
            sorted_list = sortareLista(lista, sortare_destinatie_descresc);
    }
    printf("Lista sortata:\n");
    afisareOferte(sorted_list);
    distrugereTotala(sorted_list);
}

void filtrare_ui(ListaMea* lista)
{
    printf("Alege in functie de ce vrei sa faci filtrarea:\n");
    printf("1. destinatie\n");
    printf("2. tip\n");
    printf("3. pret\n");
    printf("4. zi\n");
    int cmd;
    char sir[200], aux;
    scanf("%d", &cmd);
    printf("Introdu criteriul de filtrare: ");
    scanf("%c", &aux);
    scanf_s("%s", sir, 200);
    ListaMea* filtred_list;
    if (cmd == 1)
        filtred_list = filtrareLista(lista, filtrare_destinatie, sir);
    else if(cmd == 2)
        filtred_list = filtrareLista(lista, filtrare_tip, sir);
    else if(cmd == 3)
        filtred_list = filtrareLista(lista, filtrare_pret, sir);
    else if (cmd == 4)
        filtred_list = filtrareLista(lista, filtrare_zi, sir);
    else
    {
        printf(ANSI_COLOR_RED"Nu ai introdus o cifra valida!\n"ANSI_COLOR_RESET);
        return;
    }
    printf("Ofertele filtrate:\n");
    afisareOferte(filtred_list);
    distrugereTotala(filtred_list);
}

ListaMea* undo_ui(ListaMea* lista_init, ListaMea* undo)
{
    if (undo->lg != 0)
    {
        return  undo_lista(lista_init, undo);
    }
    else
    {
        printf(ANSI_COLOR_RED"Nu mai am la ce sa dau undo\n"ANSI_COLOR_RESET);
        return lista_init;
    }    
}


void run()
{
    int cmd;
    ListaMea* lista = creareLista(2);
    ListaMea* undo = creareLista(2);
    while(1)
    {
        printf("\nLista actuala cu oferte: \n");
        afisareOferte(lista);
        menu();
        printf("Introdu cifra dorita: ");
        scanf("%d", &cmd);
        if(cmd == 1)
            adaugare_ui(lista, undo);
        else if(cmd == 2)
            modificare_ui(lista, undo);
        else if(cmd == 3)
            stergere_ui(lista, undo);
        else if(cmd == 4)
            sortare_ui(lista);
        else if(cmd == 5)
            filtrare_ui(lista);
        else if (cmd == 6)
            lista = undo_ui(lista, undo);
        else if(cmd == 7)
        {
            printf("BYE!");
            break;
        }
        else
            printf("Nu ai introdus o cifra valida!\n");
    }

    distrugereTotala(lista);
    if (undo->lg != 0)
    {
        for (int i=0;i<undo->lg;i++)
            distrugereTotala(undo->elems[i]);
    }
    distrugereLista(undo);
}