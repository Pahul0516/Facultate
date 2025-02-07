create database Magazin_Cafea

go 

use Magazin_Cafea

go

Create table Magazin(

ID_Magazin int primary key identity(1,1), --- identity se foloseste pentu a se genera o valoare unica incepand de la 1 si incrementand tot dun 1 in 1
nume varchar(50) not null,
locatie varchar(50) not null,
numar_de_telefon char(10),
data_infiintarii date not null,
CONSTRAINT chk_numar_de_telefon CHECK (numar_de_telefon LIKE '[0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9]') --- constrangere pt ca numarul sa fie din 10 cifre
)

Create table Manager(
	ID_Manager int foreign key references Magazin(ID_magazin),
	nume varchar(50),
	numar_de_telefon char(10),
	adresa_de_email varchar(50),
	data_angajarii date,
	departamentul varchar(50),
	CONSTRAINT chk_numar_de_telefon_manager CHECK (numar_de_telefon LIKE '[0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9]'), --- constrangere pt ca numarul sa fie din 10 cifre
	CONSTRAINT pk_manager primary key (ID_Manager)
)

Create table Angajat(
	ID_Angajat int primary key identity(1,1),
	ID_Magazin int foreign key references Magazin(ID_Magazin),
	nume varchar(50) not null,
	numar_de_telefon char(10) not null,
	adresa_de_email varchar(50) not null,
	data_angajarii date not null,
	CONSTRAINT chk_numar_de_telefon_angajat CHECK (numar_de_telefon LIKE '[0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9]') --- constrangere pt ca numarul sa fie din 10 cifre
)

Create table Salar(
	ID_Salar int foreign key references Angajat(ID_Angajat),
	valoare_brut int not null,
	valoare_net int not null,
	tva decimal(5,2) not null,
	CONSTRAINT pk_salar primary key (ID_Salar)
)

create table Client(
	ID_Client int primary key identity(1,1),
	ID_Magazin int foreign key references Magazin(ID_Magazin),
	nume varchar(50) not null,
	adresa_de_email varchar(50) not null,
	numar_de_telefon char(50),
	data_inregistrarii date not null,
	tara varchar(50) not null,
	CONSTRAINT chk_numar_de_telefon_client CHECK (numar_de_telefon LIKE '[0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9]')--- constrangere pt ca numarul sa fie din 10 cifre
)

create table Cafea (
	ID_Cafea int primary key identity(1,1),
	ID_Magazin int foreign key references Magazin(Id_Magazin),
	nume varchar(50) not null,
	descriere text not null,
	pret int not null,
	intensitate int not null,
	tara_origine varchar(50) not null,
	data_adaugarii date not null,
	CONSTRAINT chk_intensitate CHECk (intensitate BETWEEN 0 AND 13)
)

create table Biscuit(
	ID_Biscuit int primary key identity(1,1),
	ID_Magazin int foreign key references Magazin(ID_Magazin),
	nume varchar(50) not null,
	pret int not null,
	ingriedente_si_mod_de_preparare text not null,
	data_adaugarii date not null
)

create table Espresor(
	ID_Espresor int primary key identity(1,1),
	ID_Magazin int foreign key references Magazin(ID_Magazin), 
	nume varchar(50) not null,
	descriere text not null,
	pret int not null,
	tip varchar(50) not null,
	CONSTRAINT chk_tip CHECK(tip in ('Automat', 'Semi-Autoamt', 'Manual'))
)

create table Nota_Client_Cafea(
	ID_Client int foreign key references Client(ID_Client),
	ID_Cafea int foreign key references Cafea(ID_Cafea),
	CONSTRAINT pk_nota_client_cafea primary key(ID_Client, ID_Cafea)
)

create table Nota_Client_Angajat(
	ID_Client int foreign key references Client(ID_Client),
	ID_Angajat int foreign key references Angajat(ID_Angajat),
	CONSTRAINT pk_nota_client_angajat primary key(ID_Client, ID_Angajat)
)

