#pragma once
#include <iostream>
#include <string>

using std::string;

class Eveniment {
private:

	int id;
	string titlu;
	string descriere;
	string tip;
	int durata;

public:
	friend class repository;
	Eveniment();
	
	Eveniment(int id, string titlu, string descriere, string tip, int durata);

	Eveniment(const Eveniment& e);

	~Eveniment();

	int get_id() const;
	string get_titlu() const;
	string get_descriere() const;
	string get_tip() const;
	int get_durata() const;

	void set_titlu(string new_title);
	void set_descriere(string new_description);
	void set_tip(string new_type);
	void set_durata(int new_duration);

};