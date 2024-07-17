#include "repository.h"
#include "eveniment.h"
#include <algorithm>
#include <fstream>

using std::find_if;
using std::ifstream;
using std::ofstream;

void repository::repo_adauga_eveniment(const Eveniment& ev)
{
	this->lista_de_evenimente.push_back(ev);
}

void repository::repo_sterge_eveniment_dupa_id(int id)
{
	auto it = find_if(lista_de_evenimente.begin(), lista_de_evenimente.end(), [id](Eveniment ev) {return ev.get_id() == id; });
	//for (auto it = lista_de_evenimente.begin(); it != lista_de_evenimente.end(); ++it)
	//{
	//	if (it->get_id() == id)
	//	{
	//		lista_de_evenimente.erase(it);
	//		break;
	//	}
	//}
	if (it!= lista_de_evenimente.end())
		lista_de_evenimente.erase(it);

}

void repository::repo_modifica_eveniment(int id, string titlu, string descriere, string tip, int durata)
{
	for (auto ev : lista_de_evenimente)
	{
		if (ev.get_id() == id)
		{
			ev.set_titlu(titlu);
			ev.set_descriere(descriere);
			ev.set_tip(tip);
			ev.set_durata(durata);
			break;
		}
	}
}


Eveniment repository::repo_get_obiet_poz(int poz) const
{
	return this->lista_de_evenimente[poz - 1];
}

Eveniment repository::repo_get_obiet_id(int id)
{
	for (auto it = this->lista_de_evenimente.begin(); it != this->lista_de_evenimente.end(); ++it)
	{
		if (it->get_id() == id)
		{
			return *it;
		}
	}
}

int repository::repo_get_size() const
{
	return this->lista_de_evenimente.size();
}

bool repository::repo_verificare_id(int id) const
{

	auto it = find_if(lista_de_evenimente.begin(), lista_de_evenimente.end(), [=](Eveniment ev) {return ev.get_id() == id; });
	if (it != lista_de_evenimente.end())
	{
		return true;
	}
	else
	{
		return false;
	}
	//bool ok = false;
	//for (int i = 1; i <= this->repo_get_size(); i++)
	//{
	//	if (this->repo_get_obiet_poz(i).get_id() == id)
	//		ok = true;
	//}
	//return ok;
}

void fileRepo::adaugare_fisier(string nume_fisier)
{
	ofstream g (nume_fisier);
	vector<Eveniment> ev = this->get_all();
	for (auto it = ev.begin(); it != ev.end(); it++)
	{
		g << it->get_id() << " " << it->get_titlu() << " " << it->get_descriere() << " " << it->get_tip() << " " << it->get_durata() << "\n";
	}
	g.close();
}

void fileRepo::incarcare_din_fisier(string nume_fisier)
{
	ifstream f (nume_fisier);
	int id = 0, durata = 0;
	string titlu, descriere, tip, line;
	while (getline(f, line))
	{
		stringstream ff(line);
		ff >> id >> titlu >> descriere >> tip >> durata;
		Eveniment ev(id, titlu, descriere, tip, durata);
		repo_adauga_eveniment(ev);
	}
	f.close();
}

Eveniment repository::repo_get_obiet_index(int index) const
{
	return lista_de_evenimente[index];
}

