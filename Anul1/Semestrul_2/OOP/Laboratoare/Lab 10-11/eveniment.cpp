#include "eveniment.h"

Eveniment::Eveniment()
{
	this->id = 0;
	this->titlu = "";
	this->descriere = "";
	this->tip = "";
	this->durata = 0;
}

Eveniment::Eveniment(int id, string titlu, string descriere, string tip, int durata)
{
	this->id = id;
	this->titlu = titlu;
	this->descriere = descriere;
	this->tip = tip;
	this->durata = durata;
}

Eveniment::Eveniment(const Eveniment& e)
{
	this->id = e.id;
	this->titlu = e.titlu;
	this->descriere = e.descriere;
	this->tip = e.tip;
	this->durata = e.durata;
}


Eveniment::~Eveniment()
{
	this->id = 0;
	this->titlu = "";
	this->descriere = "";
	this->tip = "";
	this->durata = 0;
}

int Eveniment::get_id() const {
	return this->id;
}

string Eveniment::get_titlu() const {
	return this->titlu;
}

string Eveniment::get_descriere() const {
	return this->descriere;
}

string Eveniment::get_tip() const {
	return this->tip;
}

int Eveniment::get_durata() const {
	return this->durata;
}

void Eveniment::set_titlu(string new_title) {
	this->titlu = new_title;
}

void Eveniment::set_descriere(string new_description) {
	this->descriere = new_description;
}

void Eveniment::set_tip(string new_type) {
	this->tip = new_type;
}

void Eveniment::set_durata(int new_duration) {
	this->durata = new_duration;
}
