#include <assert.h>
#include <string>
#include "eveniment.h"
#include "repository.h"
#include "controller.h"
#include "hai_sa_fie.h"
#include "validator.h"
#include <iostream>

void teste_validator()
{
	try
	{
		verificare_date("ceva", "ceva", "ceav", "12");
		assert(true);
		verificare_date("ceva", "ceva", "ceav", "1as2");
	}
	catch (const std::exception& e)
	{
		assert(true);
	}
	try
	{
		verificare_date("ceva", "ceva", "ceav", "-12");
	}
	catch (const std::exception& e)
	{
		assert(true);
	}
	try
	{
		verificare_date("", "ceva", "ceav", "1as2");
	}
	catch (const std::exception& e)
	{
		assert(true);
	}
	try
	{
		verificare_date("ceva", "", "ceav", "1as2");
	}
	catch (const std::exception& e)
	{
		assert(true);
	}
	try
	{
		verificare_date("ceva", "ceva", "", "1as2");
	}
	catch (const std::exception& e)
	{
		assert(true);
	}

	try
	{
		verificare_date("ceva", "ceva", "ceav", "");
	}
	catch (const std::exception& e)
	{
		assert(true);
	}
}


void teste_eveniment() {
	Eveniment ev(1, "Tenis", "pe camp", "miscare", 2);
	assert(ev.get_id() == 1);
	assert(ev.get_titlu() == "Tenis");
	assert(ev.get_descriere() == "pe camp");
	assert(ev.get_tip() == "miscare");
	assert(ev.get_durata() == 2);
	ev.set_titlu("fotbal");
	assert(ev.get_titlu() == "fotbal");
	ev.set_descriere("pe terenul de fotbal");
	assert(ev.get_descriere() == "pe terenul de fotbal");
	ev.set_tip("care tip?");
	assert(ev.get_tip() == "care tip?");
	ev.set_durata(3);
	assert(ev.get_durata() == 3);
}

void teste_repository() {
	repository repo;
	Eveniment ev1(1, "Tenis", "pe camp", "miscare", 2);
	Eveniment ev2(2, "Fotbal", "pe teren", "miscare", 3);
	repo.repo_adauga_eveniment(ev1);
	assert(repo.repo_get_size() == 1);
	repo.repo_adauga_eveniment(ev2);
	assert(repo.repo_get_size() == 2);
	repo.repo_sterge_eveniment_dupa_id(1);
	repo.get_all();
	assert(repo.repo_get_size() == 1);
	auto obiect = repo.repo_get_obiet_poz(1);
	assert(obiect.get_id() == 2);
	assert(obiect.get_titlu() == "Fotbal");
	assert(obiect.get_descriere() == "pe teren");
	assert(obiect.get_tip() == "miscare");
	assert(obiect.get_durata() == 3);
	assert(repo.repo_verificare_id(2) == true);
	assert(repo.repo_verificare_id(13) == false);

}

void teste_controller()
{
	controller contr;
	contr.contr_adauga_eveniment(1, "Tenis", "pe camp", "miscare", 2);
	assert(contr.contr_get_repository(contr).repo_get_size() == 1);
	contr.contr_modifica_eveniment(1, "FOTBAL", "pe camp", "miscare", 2);
	assert(contr.contr_get_repository(contr).repo_get_obiet_poz(1).get_titlu() == "FOTBAL");
	assert(contr.contr_get_activitati(contr).get_all().size() == 0);
	vector<Eveniment> v;
	v = contr.filtrare(10);
	assert(v.size() == 1);
	v = contr.filtrare(1);
	assert(v.size() == 0);
	v = contr.sortare_dupa_durata();
	assert(v.size() == 1);
	contr.contr_sterge_eveniment_dupa_id(1);
	assert(contr.contr_get_repository(contr).repo_get_size() == 0);
	contr.contr_adauga_eveniment(1, "Fotbal", "pe camp", "miscare", 2);
	contr.contr_adauga_eveniment(1, "Baschet", "pe camp", "miscare", 2);
	contr.contr_adauga_eveniment(1, "Inot", "pe camp", "miscare", 2);
	contr.adauga_activitati(contr.contr_get_repository(contr).get_all(), "Inot");
	assert(contr.contr_get_activitati(contr).get_all().size() == 1);
	contr.golestere_activitati();
	assert(contr.contr_get_activitati(contr).get_all().size() == 0);
	contr.generare_activitati(2);
	assert(contr.contr_get_activitati(contr).get_all().size() == 2);
	contr.export_activitati("test.txt");
	contr.creare_dictionar();
}

void teste_vector_dinamic() 
{
	Eveniment ev1(1, "Tenis", "pe camp", "miscare", 2);
	Eveniment ev2(2, "Fotbal", "pe teren", "miscare", 3);
	Eveniment ev3(3, "Baschet", "pe teren", "miscare", 3);
	Eveniment ev4(4, "Volei", "pe teren", "miscare", 3);
	//int ev1 = 1;
	vectorul_meu<Eveniment> v;
	v.add(ev1);
	v.add(ev2);
	v.add(ev3);
	v.add(ev4);
	vectorul_meu<Eveniment> v2(v);
	assert(v.size() == 4);
	iterator_vector<Eveniment> it = v.begin();
	++it;
	v.erase(it);
	Eveniment ev5 = v.get(2);
	assert(ev5.get_titlu() == "Baschet");
	Eveniment ev6 = it.element();
	assert(ev6.get_titlu() == "Baschet");
  }

void rulare_teste()
{
	teste_eveniment();
	teste_validator();
	teste_repository();
	teste_controller();
	teste_vector_dinamic();
	std::cout << "Gata";
}