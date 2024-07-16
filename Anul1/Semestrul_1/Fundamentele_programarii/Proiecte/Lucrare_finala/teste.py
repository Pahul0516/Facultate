from repository import *
from entitate import *
from validare import *
from contorller import *
from datetime import *
import os 

os.system("cls")

def test_adauga_repo():
    repo=repository(validator)
    tractor1=tractoare(1,"sudfgy",5000,"sudygf",2004-12-12)
    tractor2=tractoare(1,"sudfgy",400,"sudygf",2004-12-12)


    try:
        repo.adaugare(tractor1)
        assert repo.size()==1
        repo.adaugare(tractor2)
        assert repo.size()==2
        print("totul e ok")
    except AssertionError:
        print("ceva nu e bine")

def test_stergere_repo():
    repo=repository(validator)
    tractor1=tractoare(1,"sudfgy",5000,"sudygf",2004-12-12)
    tractor2=tractoare(1,"sudfgy",400,"sudygf",2004-12-12)
    repo.adaugare(tractor2)
    repo.adaugare(tractor1)
    repo.stergere(4)

    try:
        assert repo.size()==1
        print("totul e ok")
    except AssertionError:
        print("ceva nu e bine")


def test_adaugare_fisier():
    repo=repository(validator)
    repo.adaugare_fisier()

    try:
        assert repo.size()==4
        print("totul e ok")
    except AssertionError:
        print("ceva nu e bine")

def test_adauga_contr():
    repo=repository(validator)
    contr=controller(repo)


    try:
        id = 1
        denumire = "skdfghj"
        pret = 1212
        model = "sjgdf"
        data = date(2001,1,1)
        contr.adaugare(id,denumire,pret,model,data)
        assert contr.repo_tractor.size()==1
        contr.adaugare(id,denumire,pret,model,data)
        assert contr.repo_tractor.size()==2
        print("totul e ok")
    except AssertionError:
        print("ceva nu e bine")


def test_sterge_contr():
    repo=repository(validator)
    contr=controller(repo)
    id = 1
    denumire = "skdfghj"
    pret = 1212
    model = "sjgdf"
    data = date(2001,1,1)
    contr.adaugare(id,denumire,pret,model,data)
    pret=8000
    contr.adaugare(id,denumire,pret,model,data)

    try:
        contr.stergere(2)
        assert contr.repo_tractor.size()==1
        contr.stergere(8)
        assert contr.repo_tractor.size()==0
        print("totul e ok")
    except AssertionError:
        print("ceva nu e bine")

def test_get_id():
    tractor1=tractoare(1,"asjdgv",3000,"shdgfv",2004-12-12)
    tractor2=tractoare(2,"asjdgv",3000,"shdgfv",2004-12-12)

    try:
        assert tractor1.get_id()==1
        assert tractor2.get_id()==2
        print("totul e ok")
    except AssertionError:
        print("ceva nu e bine")

def test_get_denumire():
    tractor1=tractoare(1,"tractor1",3000,"shdgfv",2004-12-12)
    tractor2=tractoare(2,"tractor2",3000,"shdgfv",2004-12-12)

    try:
        assert tractor1.get_denumire()=="tractor1"
        assert tractor2.get_denumire()=="tractor2"
        print("totul e ok")
    except AssertionError:
        print("ceva nu e bine")

def test_get_pret():
    tractor1=tractoare(1,"tractor1",3000,"shdgfv",2004-12-12)
    tractor2=tractoare(2,"tractor2",3500,"shdgfv",2004-12-12)

    try:
        assert tractor1.get_pret()==3000
        assert tractor2.get_pret()==3500
        print("totul e ok")
    except AssertionError:
        print("ceva nu e bine")

def test_get_model():
    tractor1=tractoare(1,"tractor1",3000,"ceva",2004-12-12)
    tractor2=tractoare(2,"tractor2",3500,"altceva",2004-12-12)

    try:
        assert tractor1.get_model()=="ceva"
        assert tractor2.get_model()=="altceva"
        print("totul e ok")
    except AssertionError:
        print("ceva nu e bine")



test_adauga_repo()
test_stergere_repo()
test_adaugare_fisier()
test_adauga_contr()
test_sterge_contr()
test_get_id()
test_get_denumire()
test_get_pret()
test_get_model()