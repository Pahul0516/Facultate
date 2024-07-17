#include "controller.h"
#include "eveniment.h"
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <map>
#include <fstream>
#include <string>
#include "actiune_undo.h"


using std::to_string;
using std::copy_if;
using std::ofstream;
using std::map;

void controller::contr_adauga_eveniment(string titlu, string descriere, string tip, string durata)
{
	int fr[100000] = { 0 };
	int id = 0;
	for (auto it : repo.get_all())
	{
		fr[it.get_id()] = 1;
	}
	int i = 1;
	for (i = 1; i <= 10000; i++)
	{
		if (fr[i] == 0)
		{
			break;
		}
	}
	id = i;
	int d = stoi(durata);
	Eveniment ev(id, titlu, descriere, tip, d);
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
	this->undoActions.push_back(new undoModifica{ this->repo, ev, ev2 });
}

vector<Eveniment> controller::filtrare( int(*filtrare)(Eveniment, string), string sir)
{
	vector<Eveniment> lista_filtrata, lista_de_parcurs;
	lista_de_parcurs = this->repo.get_all();

	for (auto it = lista_de_parcurs.begin(); it != lista_de_parcurs.end(); ++it)
	{
		Eveniment ev = *it;
		if (filtrare(ev, sir)==0)
		{
			lista_filtrata.push_back(ev);
		}
	}

	//copy_if(lista_de_parcurs.begin(), lista_de_parcurs.end(), back_inserter(lista_filtrata), [nr](Eveniment ev) {
	//	return ev.get_durata() <= nr;
	//	});
	return lista_filtrata;

}


vector<Eveniment> controller::sortare(int(*sortare)(Eveniment, Eveniment))
{
	vector<Eveniment> lista_sortata, lista_de_parcurs;
	lista_de_parcurs = this->repo.get_all();
	//lista_sortata = lista_de_parcurs;

	//for (auto it1 = lista_sortata.begin(); it1 != lista_sortata.end(); ++it1)
	//{
	//	for (auto it2 = it1; it2 != lista_sortata.end(); ++it2)
	//	{
	//		if (sortare(*it1, *it2) == 1)
	//		{
	//			swap(it1, it2);
	//		}
	//	}
	//}


	copy(lista_de_parcurs.begin(), lista_de_parcurs.end(), back_inserter(lista_sortata));
	sort(lista_sortata.begin(), lista_sortata.end(), sortare);

	return lista_sortata;
}

void controller::adauga_activitati(vector<Eveniment> lista, string titlu, bool& ok)
{
	for (auto ev : lista)
	{
		if (ev.get_titlu() == titlu)
		{
			ok = true;
			this->activitati.get_all().push_back(ev);
		}
	}
	notify();
}

void controller::golestere_activitati()
{
	this->activitati.get_all().clear();
	notify();
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
	notify();
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
	notify();

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
	repo_fisier.adaugare_fisier(nume_fisier);
}


void controller::read_form_file(string nume_fisier)
{
	fileRepo repo_fisier{ repo };
	repo_fisier.incarcare_din_fisier(nume_fisier);
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

vector<string> controller::contr_find(int id)
{
	vector<string> lista;
	vector<Eveniment> lista_de_evenimente = repo.get_all();

	auto ev = find_if(lista_de_evenimente.begin(), lista_de_evenimente.end(), [=](Eveniment ev) {return ev.get_id() == id; });

	lista.push_back(ev->get_titlu());
	lista.push_back(ev->get_descriere());
	lista.push_back(ev->get_tip());
	lista.push_back(to_string(ev->get_durata()));

	return lista;
}

controller::~controller()
{
	for (auto act : undoActions) {
		delete act;
	}
}

Eveniment controller::contr_get_eveniment_dupa_index(int index) const
{
	return repo.repo_get_obiet_index(index);
}
