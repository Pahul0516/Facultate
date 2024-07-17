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

fileRepo::fileRepo(repository r)
{
	lista_de_evenimente = r.get_all();
}

void fileRepo::adaugare_fisier(fileRepo r, string nume_fisier)
{
	ofstream g (nume_fisier);
	vector<Eveniment> ev = r.lista_de_evenimente;
	for (auto it = ev.begin(); it != ev.end(); it++)
	{
		g << it->get_id() << " " << it->get_titlu() << " " << it->get_descriere() << " " << it->get_tip() << " " << it->get_durata() << "\n";
	}
	g.close();
}

void fileRepo::incarcare_din_fisier(fileRepo& r, string nume_fisier)
{
	ifstream f (nume_fisier);
	int id, durata;
	string titlu, descriere, tip;
	while (f >> id >> titlu >> descriere >> tip >> durata)
	{
		Eveniment ev(id, titlu, descriere, tip, durata);
		r.repo_adauga_eveniment(ev);
	}
	f.close();
}

