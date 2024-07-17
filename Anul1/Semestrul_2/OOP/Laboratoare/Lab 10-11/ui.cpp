#include <iostream>
#include <string>
#include "ui.h"
#include <cstdlib>
#include <windows.h>
#include "validator.h"
#include "vector_dinamic.h"
#include "utils.h"
#include <map>

using std::cin;
using std::cout;
using std::string;
using std::system;
using std::map;


void ui::afisare_optiuni() const
{
	cout << "1. Curatare consola\n";
	cout << "2. Adaugare eveniment\n";
	cout << "3. Stergere eveniment\n";
	cout << "4. Modificare eveniment\n";
	cout << "5. Filtrare\n";
	cout << "6. Sortare\n";
	cout << "7. Afiseaza lista personala\n";
	cout << "8. Adauga o activitate dupa titlu\n";
	cout << "9. Stergere lista personala\n";
	cout << "10. Generare o lista aleatorie\n";
	cout << "11. Exportare lista personala\n";
	cout << "12. Frecventa evenimente\n";
	cout << "13. Adaugare in fisier\n";
	cout << "14. Citire din fisier\n";
	cout << "15. Undo\n";
	cout << "16. Exit\n";

}

void ui::ui_curatare() const
{
	system("cls");
}


void ui::ui_afisare(vector<Eveniment> lista) const
{
	cout << "\n";
	if (lista.size() != 0)
	{
		//for (int i = 1; i <= this->contr.contr_get_repository(this->contr).repo_get_size(); i++)
		//{
		//	cout << "Id: " << this->contr.contr_get_repository(this->contr).repo_get_obiet_poz(i).get_id() << " ";
		//	cout << "Titlu: " << this->contr.contr_get_repository(this->contr).repo_get_obiet_poz(i).get_titlu() << " ";
		//	cout << "Descriere: " << this->contr.contr_get_repository(this->contr).repo_get_obiet_poz(i).get_descriere() << " ";
		//	cout << "Tip: " << this->contr.contr_get_repository(this->contr).repo_get_obiet_poz(i).get_tip() << " ";
		//	cout << "Durata: " << this->contr.contr_get_repository(this->contr).repo_get_obiet_poz(i).get_durata() << " ";
		//	cout << "\n";
		//}
		for (auto ev : lista)
		{
			cout << "Id: " << ev.get_id() << " ";
			cout << "Titlu: " << ev.get_titlu() << " ";
			cout << "Descriere: " << ev.get_descriere() << " ";
			cout << "Tip: " << ev.get_tip() << " ";
			cout << "Durata: " << ev.get_durata() << " ";
			cout << "\n";
		}
	}
	cout << "\n";
}


void ui::ui_adaugare()
{
	string titlul, descrierea, tipul, durata1;
	int durata, id = 1;
	cout << "Te rog sa introduci titlul evenimentului: ";
	cin >> titlul;
	cout << "Te rog sa introduci descrierea evenimentului: ";
	cin >> descrierea;
	cout << "Te rog sa introduci tipul evenimentului: ";
	cin >> tipul;
	cout << "Te rog sa introduci durata evenimentului: ";
	cin >> durata1;
	try
	{

		verificare_date(titlul, descrierea, tipul, durata1);
		durata = std::stoi(durata1);
		if (this->contr.contr_get_repository(this->contr).repo_get_size() == 0)
			id = 1;
		else
		{
			int maxi = -1;
			for (int i = 1; i <= this->contr.contr_get_repository(this->contr).repo_get_size(); i++)
				if (this->contr.contr_get_repository(this->contr).repo_get_obiet_poz(i).get_id() > maxi)
					maxi = this->contr.contr_get_repository(this->contr).repo_get_obiet_poz(i).get_id();
			id = maxi + 1;
		}
		this->contr.contr_adauga_eveniment(titlul, descrierea, tipul, durata1);
		cout << "\n\x1B[37m\x1B[32mAdaugat cu succes" << "\x1B[37m";
	}
	catch (const std::exception& e)
	{
		cout << "\n\x1B[37m\x1B[31m" << e.what() << "\x1B[37m";
	}
}

void ui::ui_stergere()
{
	int id;
	cout << "Te rog sa introduci id-ul evenimentului pe care vrei sa il stergi: ";
	cin >> id;
	if (this->contr.contr_get_repository(this->contr).repo_verificare_id(id) == true)
	{
		this->contr.contr_sterge_eveniment_dupa_id(id);
		cout << "\n\x1B[37m\x1B[32mSters cu succes" << "\x1B[37m";
	}
	else 
		cout << "\n\x1B[37m\x1B[31mNu exista un element cu acest id" << "\x1B[37m";
}

void ui::ui_modificare()
{
	int id;
	cout << "Te rog sa introduci id-ul evenimentului pe care vrei sa il modifici: ";
	cin >> id;
	string titlul, descrierea, tipul, durata1;
	int durata;
	cout << "Te rog sa introduci titlul evenimentului: ";
	cin >> titlul;
	cout << "Te rog sa introduci descrierea evenimentului: ";
	cin >> descrierea;
	cout << "Te rog sa introduci tipul evenimentului: ";
	cin >> tipul;
	cout << "Te rog sa introduci durata evenimentului: ";
	cin >> durata1;
	try
	{
		verificare_date(titlul, descrierea, tipul, durata1);
		durata = std::stoi(durata1);
		if (this->contr.contr_get_repository(this->contr).repo_verificare_id(id) == true)
		{
			this->contr.contr_modifica_eveniment(id, titlul, descrierea, tipul, durata);
			cout << "\n\x1B[37m\x1B[32mModificat cu succes" << "\x1B[37m";
		}
		else
			cout << "\n\x1B[37m\x1B[31mNu exista un element cu acest id" << "\x1B[37m";
	}
	catch (const std::exception& e)
	{
		cout << "\n\x1B[37m\x1B[31m" << e.what() << "\x1B[37m";
	}
}


void ui::ui_filtrare()
{
	vector<Eveniment> lista_filtrata;
	int numar;
	cout << "Te rog sa introduci numarul dupa care vrei sa se faca filtrarea: ";
	cin >> numar;
	
	lista_filtrata = this->contr.filtrare(filtrare_descriere, std::to_string(numar));
	if (lista_filtrata.size() == 0)
		cout << "\n\x1B[37m\x1B[31mNu exista evenimente cu durata mai mare decat " << numar << "\x1B[37m";
	else
	{
		cout << "\n\x1B[33mEvenimentele care au durata mai mica decat " << numar << " sunt: \n\x1B[37m";
		ui_afisare(lista_filtrata);
	}	
}

void ui::ui_sortare()
{
	vector<Eveniment> lista_sortata;
	//lista_sortata = this->contr.sortare(sortare_durata);
	cout << "\n\x1B[33mEvenimentele sortate dupa durata sunt: \n\x1B[37m";
	ui_afisare(lista_sortata);
}


void ui::ui_afisare_lista_personala()
{
	vector<Eveniment> lista;
	lista = this->contr.contr_get_activitati(this->contr).get_all();
	if (lista.size() != 0)
	{
		cout << "\n\x1B[34mLista dumneavoastra personala este: " << "\n\x1B[37m";
		this->ui_afisare(lista);
	}
	else
	{
		cout << "\n\x1B[31mNu ati creat o lista personala" << "\n\x1B[37m";
	}
}

void ui::ui_adaugare_lista_dupa_nume()
{
	bool ok = false;
	string nume;
	cout << "Va rog sa introduceti numele activitatii pe care doriti sa o adaugati in lista personala: ";
	cin >> nume;
	this->contr.adauga_activitati(this->contr.contr_get_repository(this->contr).get_all(), nume, ok);
	cout << "\n\x1B[37m\x1B[32mAdaugat cu succes" << "\x1B[37m";
}

void ui::ui_stergere_lista_personala()
{
	vector <Eveniment> lista;
	lista= this->contr.contr_get_activitati(this->contr).get_all();
	if (lista.size() == 0)
	{
		cout << "\n\x1B[31mNu ati creat o lista personala" << "\n\x1B[37m";
	}
	else
	{
		this->contr.golestere_activitati();
		cout << "\n\x1B[37m\x1B[32mLista personala a fost stearsa cu succes" << "\n\x1B[37m";
	}

}


void  ui::ui_generare_activitati()
{
	int nr;
	cout << "Va rog sa introduceti numarul de evenimente pe care le doriti generate random in lista dumneavoastra: ";
	cin >> nr;
	this->contr.generare_activitati(nr);
	cout << "\n\x1B[37m\x1B[32mGenerat cu succes" << "\n\x1B[37m";
}

void ui::ui_export_activitati()
{
	string fisier;
	cout << "Va rog sa introduceti numele fisierului in care doriti sa exportati lista personala: ";
	cin >> fisier;
	this->contr.export_activitati(fisier);
	cout << "\n\x1B[37m\x1B[32mExportat cu succes" << "\n\x1B[37m";
}

void ui::ui_frecventa_evenimente()
{
	map<string, int > dictionar;
	dictionar = this->contr.creare_dictionar();
	cout << "\n\x1B[33mFrecventa evenimentelor este: \n\x1B[37m";
	for (auto it : dictionar)
	{
		cout << it.first << " " << it.second << "\n";
	}
}

void ui::ui_adaugare_in_fisier()
{
	string nume_fisier;
	cout << "Te rog sa introduci numele fisierului in care vrei sa adaugi evenimente: ";
	cin >> nume_fisier;
	this->contr.write_to_file(nume_fisier);
	cout << "\n\x1B[37m\x1B[32mAdaugat cu succes" << "\n\x1B[37m";
}

void ui::ui_citire_din_fisier()
{
	string nume_fisier;
	cout << "Te rog sa introduci numele fisierului din care vrei sa citesti evenimente: ";
	cin >> nume_fisier;
	this->contr.read_form_file(nume_fisier);

	cout << "\n\x1B[37m\x1B[32mCitit cu succes" << "\n\x1B[37m";
}

void ui::ui_undo()
{
	this->contr.contr_undo();
	cout << "\n\x1B[37m\x1B[32mUndo efectuat cu succes" << "\n\x1B[37m";
}


void ui::run()
{
	cout << ":P \n";
	int cmd;
	while (true)
	{
		if (this->contr.contr_get_repository(this->contr).repo_get_size() == 0)
			cout << "\nLista de evenimente este goala\n";
		else 
			cout << "\nLista de evenimente este: \n";
		ui_afisare(this->contr.contr_get_repository(this->contr).get_all());
		afisare_optiuni();
		cout << "Te rog sa introduci una din optiunile de mai sus: ";
		cin >> cmd;
		if (cmd == 1)
			ui_curatare();
		else if (cmd == 2)
			ui_adaugare();
		else if (cmd == 3)
			ui_stergere();
		else if (cmd == 4)
			ui_modificare();
		else if (cmd == 5)
			ui_filtrare();
		else if (cmd == 6)
			ui_sortare();
		else if (cmd == 7)
			ui_afisare_lista_personala();
		else if (cmd == 8)
			ui_adaugare_lista_dupa_nume();
		else if (cmd == 9)
			ui_stergere_lista_personala();
		else if (cmd == 10)
			ui_generare_activitati();
		else if (cmd == 11)
			ui_export_activitati();
		else if (cmd == 12)
			ui_frecventa_evenimente();
		else if (cmd == 13)
			ui_adaugare_in_fisier();
		else if (cmd == 14)
			ui_citire_din_fisier();
		else if (cmd == 15)
			ui_undo();
		else if(cmd == 16)
		{
			cout << "\n" << "\x1B[37m\x1B[35mGata treaba pe aici! terminasi" << "\n" << "\x1B[37m";
			break;
		}
		else 
		{
			cout << "\n" << "\x1B[37m\x1B[31mNu exista o asemenea optiune :(\n " << "\x1B[37m";
		}
	}
}
