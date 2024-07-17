#pragma once
#include "eveniment.h"


int filtrare_descriere(Eveniment ev, string descriere);
int filtrare_tip(Eveniment ev, string tip);
int filtrare_durata(Eveniment ev, string durata);



int sortare_titlu(Eveniment ev1, Eveniment ev2);
int sortare_descriere(Eveniment ev1, Eveniment ev2);
int sortare_tip(Eveniment ev1, Eveniment ev2);
int sortare_durata(Eveniment ev1, Eveniment ev2);

//void sortare_tip_plus_durata();