#include "GUI.h"

ProductGui::ProductGui()
{
	table_init();
	gui_init();
	//load_data();
	init_connect();
}

void ProductGui::gui_init()
{
	this->setLayout(ly_main);



	colectare_date->addRow("Titlu: ", text_titlu);
	colectare_date->addRow("Descriere: ", text_descriere);
	colectare_date->addRow("Tip: ", text_tip);
	colectare_date->addRow("Durata: ", text_durata);

	actiuni->addLayout(colectare_date);




	ly_btn1->addWidget(bt1);
	ly_btn1->addWidget(bt2);
	ly_btn1->addWidget(bt3);
	ly_btn1->addWidget(bt4);

	ly_btns->addLayout(ly_btn1);

	ly_btn2->addWidget(bt5);

	ly_sort->addWidget(bt12);
	ly_sort->addWidget(bt13);
	ly_sort->addWidget(bt14);
	ly_sort->addWidget(bt15);
	ly_sort->addWidget(bt6);


	ly_btn2->addLayout(ly_sort);
	ly_btn2->addWidget(bt7);

	ly_btns->addLayout(ly_btn2);


	ly_btn3->addWidget(bt16);

	//ly_btn3->addWidget(bt8);
	//ly_btn3->addWidget(bt9);
	//ly_btn3->addWidget(bt10);
	//ly_btn3->addWidget(bt11);

	ly_text->setAlignment(Qt::AlignHCenter);
	ly_btns->addLayout(ly_text);
	ly_btns->addLayout(ly_btn3);



	actiuni->addLayout(ly_btns);
	actiuni->setAlignment(Qt::AlignTop);
	//actiuni->addWidget(lista_mea);


	ly_main->addLayout(actiuni);


	lista_activitati2->setModel(model);
	ly_lists->addWidget(lista_activitati2);


	//ly_lists->addWidget(lista_filtrare);




	ly_main->addLayout(ly_lists);

	//this->show();

}

void ProductGui::table_init() {
	this->contr.read_form_file("Date_de_inceput.txt");
}

//void ProductGui::load_data()
//{
//	lista_activitati->clear();
//	repository repo = contr.contr_get_repository(contr);
//	for (auto it : repo.get_all())
//	{
//		int s1 = it.get_id();
//		string s2 = it.get_titlu();
//		string s3 = it.get_descriere();
//		string s4 = it.get_tip();
//		int s5 = it.get_durata();
//
//		string s11 = std::to_string(s1);
//		string s51 = std::to_string(s5);
//
//		string afis = s11 + " " + s2 + " " + s3 + " " + s4 + " " + s51;
//        
//		QListWidgetItem* item = new QListWidgetItem(QString::fromStdString(afis));
//		item->setData(Qt::UserRole, s1);
//
//		lista_activitati->addItem(item);
//	
//		text_titlu->clear();
//		text_descriere->clear();
//		text_tip->clear();
//		text_durata->clear();
// 	}
//}

//void ProductGui::load_data(vector<Eveniment> l)
//{
//	lista_activitati->clear();
//	for (auto it : l)
//	{
//		int s1 = it.get_id();
//		string s2 = it.get_titlu();
//		string s3 = it.get_descriere();
//		string s4 = it.get_tip();
//		int s5 = it.get_durata();
//
//		string s11 = std::to_string(s1);
//		string s51 = std::to_string(s5);
//
//		string afis = s11 + " " + s2 + " " + s3 + " " + s4 + " " + s51;
//
//		QListWidgetItem* item = new QListWidgetItem(QString::fromStdString(afis));
//		item->setData(Qt::UserRole, s1);
//
//		lista_activitati->addItem(item);
//
//		text_titlu->clear();
//		text_descriere->clear();
//		text_tip->clear();
//		text_durata->clear();
//	}
//}



void ProductGui::init_connect()
{
	connect(bt1, &QPushButton::clicked, [&]() {

		auto titlu = text_titlu->text();
		auto descriere = text_descriere->text();
		auto tip = text_tip->text();
		auto durata = text_durata->text();

		try
		{
			verificare_date(titlu.toStdString(), descriere.toStdString(), tip.toStdString(), durata.toStdString());
			contr.contr_adauga_eveniment(titlu.toStdString(), descriere.toStdString(), tip.toStdString(), durata.toStdString());
			//load_data();
			model->reload();
			
		}
		catch (const std::exception& e)
		{
			QMessageBox::information(nullptr, "Erori", "Date invaliede");
		}
		}
	);

	connect(bt2, &QPushButton::clicked, [&]() {
		auto sel = lista_activitati->selectedItems();
		if (sel.isEmpty())
		{
			QMessageBox::information(nullptr, "Erori", "Nu ai selectat un element de sters");
		}
		else
		{
			int id = sel.at(0)->data(Qt::UserRole).toInt();
			contr.contr_sterge_eveniment_dupa_id(id);
			//load_data();
		}
		}
	);

	connect(bt3, &QPushButton::clicked, [&]() {
		
		QWidget* w = new QWidget;
		QVBoxLayout* ly = new QVBoxLayout;
		w->setLayout(ly);
		QFormLayout* tabel = new QFormLayout;
		QLineEdit* text_id = new QLineEdit;
		QPushButton* bt_ok = new QPushButton{ "Ok" };
		ly->addLayout(tabel);
		tabel->addRow("Te rog sa introduci id-ul pe care vrei sa il modifici", text_id);
		ly->addWidget(bt_ok);

		connect(bt_ok, &QPushButton::clicked, [&, text_id, w]() {
			qDebug() << "ceva";
			auto id = text_id->text();
			auto titlu = text_titlu->text();
			auto descriere = text_descriere->text();
			auto tip = text_tip->text();
			auto durata = text_durata->text();

			try
			{
				verificare_existanta_id(id.toInt(), contr.contr_get_repository(contr));
				verificare_date(titlu.toStdString(), descriere.toStdString(), tip.toStdString(), durata.toStdString());
				contr.contr_modifica_eveniment(id.toInt(), titlu.toStdString(), descriere.toStdString(), tip.toStdString(), durata.toInt());
				//load_data();
				w->close();
			}
			catch (const std::exception& e)
			{
				QMessageBox::information(nullptr, "Erori", "Date invalide");
				w->close();
			}

			});
		 
		w->show();


		});

	connect(bt4, &QPushButton::clicked, [&]() {
		contr.contr_undo();
		//load_data();

		});

	connect(bt5, &QPushButton::clicked, [&]() {
		QWidget* w_fil = new QWidget;
		QVBoxLayout* ly_fil = new QVBoxLayout;

		w_fil->setLayout(ly_fil);
		QHBoxLayout* ly_info_fil = new QHBoxLayout;
		QLabel* info_fil = new QLabel{"Cum vrei sa se faca filtrarea?"};
		ly_info_fil->addWidget(info_fil);
		ly_info_fil->setAlignment(Qt::AlignCenter);

		QHBoxLayout* ly_bnts_fil = new QHBoxLayout;
		QPushButton* bt1_fil = new QPushButton{"Descriere"};
		QPushButton* bt2_fil = new QPushButton{"Tip"};
		QPushButton* bt3_fil = new QPushButton{"Durata"};

		ly_bnts_fil->addWidget(bt1_fil);
		ly_bnts_fil->addWidget(bt2_fil);
		ly_bnts_fil->addWidget(bt3_fil);

		ly_fil->addLayout(ly_info_fil);
		ly_fil->addLayout(ly_bnts_fil);

		w_fil->show();

		connect(bt1_fil, &QPushButton::clicked, [&, w_fil]() {
			lista_filtrare->clear();
			string sir = text_descriere->text().toStdString();
			if (sir == "")
			{
				QMessageBox::information(nullptr, "Erori", "Nu ai introdus campul dupa care sa se faca filtrarea");
				w_fil->close();
			}
			else
			{
				auto l = contr.filtrare(filtrare_descriere, sir);
				for (auto ev : l)
				{
					QListWidgetItem* item = new QListWidgetItem{ QString::number(ev.get_id()) + " " + QString::fromStdString(ev.get_titlu()) + " " + QString::fromStdString(ev.get_descriere()) + " " + QString::fromStdString(ev.get_tip()) + " " + QString::number(ev.get_durata())};
					lista_filtrare->addItem(item);
				}
				load_fil_table();
				w_fil->close();
			}
			});

		connect(bt2_fil, &QPushButton::clicked, [&, w_fil]() {
			lista_filtrare->clear();
			string sir = text_tip->text().toStdString();
			if (sir == "")
			{
				QMessageBox::information(nullptr, "Erori", "Nu ai introdus campul dupa care sa se faca filtrarea");
				w_fil->close();
			}
			else
			{
				auto l = contr.filtrare(filtrare_tip, sir);
				for (auto ev : l)
				{
					QListWidgetItem* item = new QListWidgetItem{ QString::number(ev.get_id()) + " " + QString::fromStdString(ev.get_titlu()) + " " + QString::fromStdString(ev.get_descriere()) + " " + QString::fromStdString(ev.get_tip()) + " " + QString::number(ev.get_durata()) };
					lista_filtrare->addItem(item);
				}
				load_fil_table();
				w_fil->close();
			}
			});

		connect(bt3_fil, &QPushButton::clicked, [&, w_fil]() {
			lista_filtrare->clear();
			string sir = text_durata->text().toStdString();
			if (sir == "")
			{
				QMessageBox::information(nullptr, "Erori", "Nu ai introdus campul dupa care sa se faca filtrarea");
				w_fil->close();
			}
			else
			{
				auto l = contr.filtrare(filtrare_durata, sir);
				for (auto ev : l)
				{
					QListWidgetItem* item = new QListWidgetItem{ QString::number(ev.get_id()) + " " + QString::fromStdString(ev.get_titlu()) + " " + QString::fromStdString(ev.get_descriere()) + " " + QString::fromStdString(ev.get_tip()) + " " + QString::number(ev.get_durata()) };
					lista_filtrare->addItem(item);
				}
				load_fil_table();
				w_fil->close();
			}
			});



		});

	connect(bt12, &QRadioButton::toggled, [&]() {
		connect(bt6, &QPushButton::pressed, [&]() {
			vector<Eveniment> l = contr.sortare(sortare_titlu);
			//load_data(l);
			});
		});

	connect(bt13, &QRadioButton::toggled, [&]() {
		connect(bt6, &QPushButton::pressed, [&]() {
			vector<Eveniment> l = contr.sortare(sortare_descriere);
			//load_data(l);
			});
		});

	connect(bt14, &QRadioButton::toggled, [&]() {
		connect(bt6, &QPushButton::pressed, [&]() {
			vector<Eveniment> l = contr.sortare(sortare_tip);
			//load_data(l);
			});
		});

	connect(bt15, &QRadioButton::toggled, [&]() {
		connect(bt6, &QPushButton::pressed, [&]() {
			vector<Eveniment> l = contr.sortare(sortare_durata);
			//load_data(l);
			});
		});

	connect(bt6, &QPushButton::released, [&]() {
		//load_data();

		});

	connect(bt7, &QPushButton::clicked, [&]() {
		text_titlu->setText("");
		text_descriere->setText("");
		text_tip->setText("");
		text_durata->setText("");
		lista_filtrare->clear();
		load_fil_table();
		});


	connect(bt16, &QPushButton::clicked, [&]() {

		widget_lista_mea* w_l = new widget_lista_mea{ &contr };
		Desenare* d = new Desenare{ &contr };

		d->show();
		w_l->show();

		});

	connect(lista_activitati, &QListWidget::itemSelectionChanged, [&]() {
		auto sel = lista_activitati->selectedItems();

		if (sel.isEmpty())
		{
			text_titlu->setText("");
			text_descriere->setText("");
			text_tip->setText("");
			text_durata->setText("");
		}
		else
		{
			int id = sel.at(0)->data(Qt::UserRole).toInt();
			vector<string> l = contr.contr_find(id);

			text_titlu->setText(QString::fromStdString(l[0]));
			text_descriere->setText(QString::fromStdString(l[1]));
			text_tip->setText(QString::fromStdString(l[2]));
			text_durata->setText(QString::fromStdString(l[3]));
		}
		});
}

void ProductGui::load_fil_table()
{
	bool isEmpty = lista_filtrare->count();
	if (isEmpty == 1)
	{
		ly_lists->addWidget(lista_filtrare);
		lista_filtrare->show();
	}
	else {
		ly_lists->removeWidget(lista_filtrare);
		lista_filtrare->hide();
	}
}

void widget_lista_mea::gui_init()
{
	ly_btns_li->addWidget(bt1_li);
	ly_btns_li->addWidget(bt2_li);
	ly_btns_li->addWidget(bt3_li);
	ly_btns_li->addWidget(bt4_li);

	ly_info_li->addWidget(info1_li);
	if (contr->contr_get_activitati(*contr).get_all().size() == 0)
		ly_info_li->addWidget(info2_li);

	ly_info_li->setAlignment(Qt::AlignCenter);

	ly_lista_li->addWidget(lista_li);
	//ly_lista_li->addWidget(tabel);

	colectare_date_li->addRow("Denumirea pe care vrei sa o aduagi", adaugare_li);
	colectare_date_li->addRow("Cate activitati vrei sa generezi", numar_activitati_li);


	ly_main_li->addLayout(ly_info_li);
	ly_main_li->addLayout(colectare_date_li);
	ly_main_li->addLayout(ly_btns_li);
	ly_main_li->addLayout(ly_lista_li);


	this->setLayout(ly_main_li);

}

void widget_lista_mea::init_connect()
{
	
	connect(bt1_li, &QPushButton::clicked, [&](){
		bool ok = false;
		contr->adauga_activitati(contr->contr_get_repository(*contr).get_all(), adaugare_li->text().toStdString(), ok);
		adaugare_li->clear();
		if (ok == false)
			QMessageBox::information(nullptr, "Erori", "Nu exista un astfel de eveniment");
		});

	connect(bt2_li, &QPushButton::clicked, [&]() {
		if (contr->contr_get_activitati(*contr).get_all().size() != 0)
			contr->golestere_activitati();
		else
			QMessageBox::information(nullptr, "Erori", "Lista e deja goala");

		});

	connect(bt3_li, &QPushButton::clicked, [&]() {

		if (numar_activitati_li->text().toInt() > 0)
		{
			contr->generare_activitati(numar_activitati_li->text().toInt());
			numar_activitati_li->clear();
		}
		else
		{
			QMessageBox::information(nullptr, "Erori", "Valoarea pe care vrei sa o generezi trebuie sa fie mai mare ca 0 si pozitiva");
		}

		});

	connect(bt4_li, &QPushButton::clicked, [&]() {
		if (contr->contr_get_activitati(*contr).get_all().size() != 0)
		{
			contr->export_activitati("Activitati_exportate.txt");
			QMessageBox::information(nullptr, "Informatii", "Datele au fost exportate cu succes. Le poti gasi in Activitati_exportate.txt");
		}
		else
		{
			QMessageBox::information(nullptr, "Erori", "Nu pot exporta ceva ce e vid");
		}
		});

}

void widget_lista_mea::load_data()
{
	lista_li->clear();
	repository repo = contr->contr_get_activitati(*contr);
	for (auto it : repo.get_all())
	{
		int s1 = it.get_id();
		string s2 = it.get_titlu();
		string s3 = it.get_descriere();
		string s4 = it.get_tip();
		int s5 = it.get_durata();

		string s11 = std::to_string(s1);
		string s51 = std::to_string(s5);

		string afis = s11 + " " + s2 + " " + s3 + " " + s4 + " " + s51;

		QListWidgetItem* item = new QListWidgetItem(QString::fromStdString(afis));
		item->setData(Qt::UserRole, s1);

		lista_li->addItem(item);
	}
}

widget_lista_mea::widget_lista_mea(controller* contr)
{
	this->contr = contr;
	contr->addObserver(this);
	contr->notify();
	gui_init();
	init_connect();
}

