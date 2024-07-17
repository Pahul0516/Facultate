#pragma once
#include "eveniment.h"
#include <vector>
#include "vector_dinamic.h"
#include <iostream>
#include <vector>

using std::vector;

class repository {

private:
	vector<Eveniment> lista_de_evenimente;

public:
	void repo_adauga_eveniment(const Eveniment& ev);
	void repo_sterge_eveniment_dupa_id(int id);

	Eveniment repo_get_obiet_poz(int poz) const;
	Eveniment repo_get_obiet_id(int id);

	bool repo_verificare_id(int id) const;
	int repo_get_size() const;
	vector<Eveniment>& get_all() { return lista_de_evenimente; }

};


class fileRepo : public repository
{
private:
	vector<Eveniment> lista_de_evenimente;

public:
	fileRepo(repository r);
	void adaugare_fisier(fileRepo r, string nume_fisier);
	void incarcare_din_fisier(fileRepo& r, string nume_fisier);
};