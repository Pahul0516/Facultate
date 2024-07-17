#pragma once
#include "eveniment.h"
#include "repository.h"
#include <iostream>

using std::cout;

class Actiune_Undo
{
public:
	virtual void doUndo() = 0;
	virtual ~Actiune_Undo() = default;
};

class undoAdauga : public Actiune_Undo{

private:
	Eveniment eveniment_adaugat;
	repository &repo;
public:
	undoAdauga(repository& repo, const Eveniment& eveniment_adaugat) :repo{ repo }, eveniment_adaugat{ eveniment_adaugat } {}
	void doUndo() override {
		repo.repo_sterge_eveniment_dupa_id(eveniment_adaugat.get_id());
	}
	~undoAdauga()
	{
		
		cout << "aici";

	}
};

class undoSterge : public Actiune_Undo {

private:
	Eveniment eveniment_sters;
	repository &repo;
public:
	undoSterge(repository& repo, const Eveniment& eveniment_sters) :repo{ repo }, eveniment_sters{ eveniment_sters } {}
	void doUndo() override {
		repo.repo_adauga_eveniment(eveniment_sters);
	}


};

class undoModifica : public Actiune_Undo {

private:
	Eveniment eveniment_modificat;
	repository repo;
public:
	undoModifica(repository& repo, const Eveniment& eveniment_modificat) :repo{ repo }, eveniment_modificat{ eveniment_modificat } {}
	void doUndo() override {
		Eveniment ev = repo.repo_get_obiet_id(eveniment_modificat.get_id());
		ev.set_descriere(eveniment_modificat.get_descriere());
		ev.set_durata(eveniment_modificat.get_durata());
		ev.set_titlu(eveniment_modificat.get_titlu());
		ev.set_tip(eveniment_modificat.get_tip());
		repo.repo_adauga_eveniment(ev);
	}
};