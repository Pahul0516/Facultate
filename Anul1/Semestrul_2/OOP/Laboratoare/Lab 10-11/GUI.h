#pragma once
#include <iostream>
#include <fstream>
#include <string>

#include <qwidget.h>
#include <qlabel.h>
#include <qlayout.h>
#include <qpushbutton.h>
#include <qlistwidget.h>
#include <QFormLayout>
#include <qlineedit.h>
#include <qdebug.h>
#include <qobject.h>
#include <qmessagebox.h>
#include <qstring.h>
#include <qradiobutton.h>
#include <qtimer.h>
#include <qtablewidget.h>
#include <qabstractitemmodel.h>

#include "controller.h"
#include "validator.h"
#include "utils.h"
#include "Observer.h"
#include "Desenare.h"

#define _CRT_SECURE_NO_WARNINGS


using std::ifstream;
using std::string;


class TestTableModel : public QAbstractTableModel
{
private:
	controller* contr;
public:
	TestTableModel(controller* c) :contr{ c } {};
	int rowCount(const QModelIndex& parent = QModelIndex())const override
	{
		return contr->contr_get_repository(*contr).get_all().size();
	}
	int columnCount(const QModelIndex& parent = QModelIndex())const override
	{
		return 1;
	}
	QVariant data(const QModelIndex& index, int role = Qt::DisplayRole)const override
	{
		if (role == Qt::DisplayRole)
		{
			vector<Eveniment> lista = contr->contr_get_repository(*contr).get_all();
			Eveniment ev = lista[index.row()];
			QString sir;
			sir = QString::number(ev.get_id()) + " " + QString::fromStdString(ev.get_titlu()) + " " + QString::fromStdString(ev.get_descriere()) + " " + QString::fromStdString(ev.get_tip()) + " " + QString::number(ev.get_durata());
			qDebug() << index.row();
			QModelIndex topLeft = createIndex(index.row(), index.column());
			return sir;
		}
		return QVariant();
	}

	void reload()
	{
		QModelIndex index1 = createIndex(0, 0);
		QModelIndex index2 = createIndex(contr->contr_get_repository(*contr).get_all().size(), contr->contr_get_repository(*contr).get_all().size());
		emit dataChanged(index1, index2);
	}

};

class ProductGui : public QWidget
{
private:

	controller contr;

	//butoane
	QPushButton* bt1 = new QPushButton{ "Adauga" };
	QPushButton* bt2 = new QPushButton{ "Sterge" };
	QPushButton* bt3 = new QPushButton{ "Modifica" };
	QPushButton* bt4 = new QPushButton{ "Undo" };


	QPushButton* bt5 = new QPushButton{ "Filtrare" };
	QPushButton* bt6 = new QPushButton{ "Sortare" };
	QPushButton* bt7 = new QPushButton{ "Refresh" };

	QRadioButton* bt12 = new QRadioButton{ "Titlu" };
	QRadioButton* bt13 = new QRadioButton{ "Descriere" };
	QRadioButton* bt14 = new QRadioButton{ "Tip" };
	QRadioButton* bt15 = new QRadioButton{ "Durata" };


	QPushButton* bt16 = new QPushButton{ "Afisare lista personala" };



	//liste
	QListWidget* lista_activitati = new QListWidget;
	QListWidget* lista_filtrare = new QListWidget;
	QListWidget* lista_mea = new QListWidget;

	//list_view

	QListView* lista_activitati2 = new QListView;
	QListView* lista_filtrare2 = new QListView;


	//layout-uri
	QHBoxLayout* ly_main = new QHBoxLayout;
	QVBoxLayout* actiuni = new QVBoxLayout;
	QFormLayout* colectare_date = new QFormLayout;
	QVBoxLayout* ly_btns = new QVBoxLayout;
	QHBoxLayout* ly_btn1 = new QHBoxLayout;
	QHBoxLayout* ly_btn2 = new QHBoxLayout;
	QHBoxLayout* ly_btn3 = new QHBoxLayout;
	QHBoxLayout* ly_text = new QHBoxLayout;
	QVBoxLayout* ly_lists = new QVBoxLayout;
	QVBoxLayout* ly_sort = new QVBoxLayout;


	//text filds


	QLineEdit* text_titlu = new QLineEdit();
	QLineEdit* text_descriere = new QLineEdit();
	QLineEdit* text_tip = new QLineEdit();
	QLineEdit* text_durata = new QLineEdit();


	TestTableModel* model = new TestTableModel{ &contr };


	void gui_init();
	void table_init();
	void init_connect();
	//void load_data();
	//void load_data(vector<Eveniment> l);
	void load_fil_table();


public:
	ProductGui();

};

class widget_lista_mea : public QWidget, public Observer
{
private:

	controller* contr;

	//butoane
	QPushButton* bt1_li = new QPushButton{ "Adaugare lista" };
	QPushButton* bt2_li = new QPushButton{ "Stergere lista" };
	QPushButton* bt3_li = new QPushButton{ "Generare lista" };
	QPushButton* bt4_li = new QPushButton{ "Exportare lista" };

	//layout-uri
	QVBoxLayout* ly_main_li = new QVBoxLayout;
	QVBoxLayout* ly_info_li = new QVBoxLayout;
	QFormLayout* colectare_date_li = new QFormLayout;
	QHBoxLayout* ly_btns_li = new QHBoxLayout;
	QHBoxLayout* ly_lista_li = new QHBoxLayout;

	//informatii
	QLabel* info1_li = new QLabel{ " Aici sunt optiunile pentru creare lista personala" };
	QLabel* info2_li = new QLabel{ "         Lista personala de activitati este goala " };

	//lista
	QListWidget* lista_li = new QListWidget;

	//tabel
	QTableWidget* tabel = new QTableWidget;

	//text fields

	QLineEdit* adaugare_li = new QLineEdit;
	QLineEdit* numar_activitati_li = new QLineEdit;

	void update() override{
		load_data();
	}


	void gui_init();
	void init_connect();
	void load_data();



public:

	widget_lista_mea(controller* contr);

};

