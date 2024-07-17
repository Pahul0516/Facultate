#include "controller.h"
#include "eveniment.h"
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <map>
#include <fstream>
#include "actiune_undo.h"

using std::copy_if;
using std::ofstream;
using std::map;

void controller::contr_adauga_eveniment(int id, string titlu, string descriere, string tip, int durata)
{
	Eveniment ev(id, titlu, descriere, tip, durata);
	this->repo.repo_adauga_eveniment(ev);
	//this->undoActions.push_back(std::make_unique<undoAdauga>(repo, ev));
	this->undoActions.push_back(new undoAdauga{ repo, ev });

}

void controller::contr_sterge_eveniment_dupa_id(int id)
{
	Eveniment ev = this->repo.repo_get_obiet_id(id);
	this->repo.repo_sterge_eveniment_dupa_id(id);
	//this->undoActions.push_back(std::make_unique<undoSterge>(repo, repo.repo_get_obiet_poz(id)));
	this->undoActions.push_back(new undoSterge{ this->repo, ev });

}

repository controller::contr_get_repository(controller& contr) const
{
	return this->repo;
}

repository controller::contr_get_activitati(controller& contr) const
{
	return this->activitati;
}

void controller::contr_modifica_eveniment(int id, string titlu, string descriere, string tip, int durata)
{
	Eveniment ev(id, titlu, descriere, tip, durata);
	Eveniment ev2 = this->repo.repo_get_obiet_id(id);
	this->repo.repo_sterge_eveniment_dupa_id(id);
	this->repo.repo_adauga_eveniment(ev);
	//this->undoActions.push_back(std::make_unique<undoModifica>(repo, repo.repo_get_obiet_poz(id))); 
	this->undoActions.push_back(new undoModifica{ this->repo, ev2 });
}

vector<Eveniment> controller::filtrare(int nr)
{
	vector<Eveniment> lista_filtrata, lista_de_parcurs;
	lista_de_parcurs = this->repo.get_all();

	//for (auto it = lista_de_parcurs.begin(); it != lista_de_parcurs.end(); ++it)
	//{
	//	if (it->get_durata() <= nr)
	//	{
	//		lista_filtrata.push_back(*it);
	//	}
	//}

	copy_if(lista_de_parcurs.begin(), lista_de_parcurs.end(), back_inserter(lista_filtrata), [nr](Eveniment ev) {
		return ev.get_durata() <= nr;
		});
	return lista_filtrata;

}


vector<Eveniment> controller::sortare_dupa_durata()
{
	vector<Eveniment> lista_sortata, lista_de_parcurs;
	lista_de_parcurs = this->repo.get_all();

	//for (auto it = lista_de_parcurs.begin(); it != lista_de_parcurs.end(); ++it)
	//{
	//	lista_sortata.push_back(*it);
	//}

	copy(lista_de_parcurs.begin(), lista_de_parcurs.end(), back_inserter(lista_sortata));
	sort(lista_sortata.begin(), lista_sortata.end(), [](Eveniment a, Eveniment b) {return a.get_durata() < b.get_durata(); });
	return lista_sortata;
}

void controller::adauga_activitati(vector<Eveniment> lista, string titlu)
{
	for (auto ev : lista)
	{
		if (ev.get_titlu() == titlu)
		{
			this->activitati.get_all().push_back(ev);
		}
	}
}

void controller::golestere_activitati()
{
	this->activitati.get_all().clear();
}

void controller::generare_activitati(int nr)
{
	int min = 1, max = this->repo.get_all().size();
	srand(time(0));
	for (int i = 0; i < nr; i++)
	{
		int val = rand() % max + 1;
		this->activitati.get_all().push_back(this->repo.get_all()[val-1]);
	}
}

void controller::export_activitati(string fisier)
{
	ofstream fout(fisier);
	vector<Eveniment> lista;
	lista = this->activitati.get_all();
	for (auto ev : lista)
	{
		fout << ev.get_id() << ", " << ev.get_titlu() << ", " << ev.get_descriere() << ", " << ev.get_tip() << ", " << ev.get_durata() << "\n";
	}
	fout.close();
}


map<string, int>controller::creare_dictionar()
{
	bool ok = false;
	map <string, int> dictionar;
	vector<Eveniment> lista;
	lista = this->repo.get_all();
	for (auto ev : lista)
	{
		ok = false;
		for (auto it : dictionar)
		{
			if (it.first == ev.get_titlu())
			{
				dictionar.erase(it.first);
				it.second++;
				dictionar.insert(it);
				ok = true;
			}
		}
		if (ok == false)
		{
			dictionar.insert(make_pair(ev.get_titlu(), 1));
		}
	}
	return dictionar;
}

void controller::write_to_file(string nume_fisier)
{
	fileRepo repo_fisier{ repo };
	repo_fisier.adaugare_fisier(repo_fisier, nume_fisier);
}


void controller::read_form_file(string nume_fisier)
{
	fileRepo repo_fisier{ repo };
	repo_fisier.incarcare_din_fisier(repo_fisier, nume_fisier);
	this->repo = repo_fisier;
}

void controller::contr_undo() {
	if (!undoActions.empty()) {

		Actiune_Undo* act = undoActions.back();
		act->doUndo();
		undoActions.pop_back();
		delete act;
	}
	// Varianta cu unique_ptr
	//obs: la obiecte unique_ptr nu putem face copie			
	//undoActions.back()->doUndo();
	//undoActions.pop_back();
}

controller::~controller()
{
	for (auto act : undoActions) {
		delete act;
	}
}