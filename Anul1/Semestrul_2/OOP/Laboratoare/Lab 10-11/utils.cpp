#include "utils.h"

int filtrare_descriere(Eveniment ev, string descriere)
{
	return strcmp(ev.get_descriere().c_str(), descriere.c_str());
}

int filtrare_tip(Eveniment ev, string tip)
{
	return strcmp(ev.get_tip().c_str(), tip.c_str());
}

int filtrare_durata(Eveniment ev, string durata)
{
	int d = stoi(durata);
	return ev.get_durata() > d;
}

int sortare_titlu(Eveniment ev1, Eveniment ev2)
{
	return ev1.get_titlu() < ev2.get_titlu();
}

int sortare_descriere(Eveniment ev1, Eveniment ev2)
{
	return ev1.get_descriere() < ev2.get_descriere();
}

int sortare_tip(Eveniment ev1, Eveniment ev2)
{
	return ev1.get_tip() < ev2.get_tip();
}

int sortare_durata(Eveniment ev1, Eveniment ev2)
{
	return ev1.get_durata() < ev2.get_durata();
}