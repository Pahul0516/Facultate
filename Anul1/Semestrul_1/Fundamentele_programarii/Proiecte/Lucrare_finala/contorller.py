from entitate import *

class controller:
    def __init__(self,repo_tractor):
        self.repo_tractor=repo_tractor

    def adaugare(self,id,denumire,pret,model,d):
        """
            functia are rolul de a contorlola adaugarea de tractoare
            primete 6 parametrii
            self 
            id 
            denumire
            pret
            model
            d - data
            creaza entitatea tractor si apeleaza functia adaugare din repo
        """
        tractor=tractoare(id,denumire,pret,model,d)
        self.repo_tractor.adaugare(tractor)

    def stergere(self,c):
        """
            functia are rolul de a controla stergerea tractoarelor
            functia returneaza numarul de tractoare sterse
            are 2 parametrii self si c- int
        """
        return self.repo_tractor.stergere(c)