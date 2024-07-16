from repository import *
from entitati import *
from validator import *

def test_stergere_repo():
    ele1=emisiune("jurnal","stiri","2","ceva stiri")
    ele2=emisiune("jurnal","televiziune","423","stiri pe bune")
    repo=repository(validator)
    repo.lista.append(ele1)
    repo.lista.append(ele2)

    try:
        repo.stergere("jurnal","stiri")
        assert repo.size()==2
        print("e ok")
    except AssertionError:
        print("ceva nu-i bine")        

test_stergere_repo()