#pragma once
#include "repository.h"
#include "eveniment.h"
#include "vector_dinamic.h"
#include <map>
#include <vector>
#include "actiune_undo.h"

using std::map;
using std::vector;
using std::unique_ptr;

class controller
{
protected:
	repository repo;
	repository activitati;
	//vector<unique_ptr<Actiune_Undo>> undoActions;
	vector<Actiune_Undo*> undoActions;

public:
	void contr_adauga_eveniment(int id, string titlu, string descriere, string tip, int durata);
	void contr_sterge_eveniment_dupa_id(int id);
	void contr_modifica_eveniment(int id, string titlu, string descriere, string tip, int durata);
	repository contr_get_repository(controller& contr) const;
	repository contr_get_activitati(controller& contr) const;
	vector<Eveniment> filtrare(int nr);
	vector<Eveniment> sortare_dupa_durata();

	void write_to_file(string nume_fisier);
	void read_form_file(string nume_fisier);


	void adauga_activitati(vector<Eveniment> lista, string titlu);
	void golestere_activitati();
	void generare_activitati(int nr);
	void export_activitati(string fisier);

	map<string, int>creare_dictionar();

	void contr_undo();

	~controller();
};