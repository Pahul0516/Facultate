#pragma once
#include "controller.h"

class ui
{
private:

	controller contr;

public:
	
	void run();
	void afisare_optiuni() const;
	void ui_afisare(vector<Eveniment> lista) const;
	void ui_curatare() const;
	void ui_adaugare();
	void ui_stergere();
	void ui_modificare();
	void ui_filtrare();
	void ui_sortare();
	void ui_afisare_lista_personala();
	void ui_adaugare_lista_dupa_nume();
	void ui_stergere_lista_personala();
	void ui_generare_activitati();
	void ui_export_activitati();
	void ui_frecventa_evenimente();
	void ui_adaugare_in_fisier();
	void ui_citire_din_fisier();
	void ui_undo();



};