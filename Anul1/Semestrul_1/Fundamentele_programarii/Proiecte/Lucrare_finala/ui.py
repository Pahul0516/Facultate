from datetime import *

class consola:

    def __init__(self,contr_tractor):
        self.contr_tractor=contr_tractor

    def adaugare(self):
        """
            functia are rolul de a lua datele de la utilizator si de a le prelucra
        """
        id=int(input("Va rog sa introduceti un id: "))
        denumire=input("Va rog sa introduceti o denumire: ")
        pret=int(input("Va rog sa introduceti un pret: "))
        model=input("Va rog sa introduceti un model: ")
        an=int(input("Va rog sa introduceti un an: "))
        luna=int(input("Va rog sa introduceti o luna: "))
        zi=int(input("Va rog sa introduceti o zi: "))
        d=date(an,luna,zi)

        self.contr_tractor.adaugare(id,denumire,pret,model,d)
        self.contr_tractor.repo_tractor.afisare_fisier()

    def stergere(self):
        """
            functia are rolul de a lua o cifra de la utilizator si de a sterge toate tractoarele 
            in a caror pret apare cifra citita
            are un singur parametru self
        """
        cifra=int(input("Va rog sa introduceti o cifra: "))
        nr_tractoare_sterse=self.contr_tractor.stergere(cifra)
        self.contr_tractor.repo_tractor.afisare_fisier()
        print("Numarul de tractoare sterse este:", nr_tractoare_sterse)


    def filtrare(self):

        """
            functia are un singur parametru self
            functia poate sa primeasca de la utilizator un sir sau un numar si o sa se realizeze o filtrare dupa sir si numar
        """
        sir=input("Va rog sa introduceti un sir daca doriti: ")
        nr=int(input("Va rog sa introduceti un numar daca doriti: "))
        if sir!='' and nr!=-1:
            for ele in self.contr_tractor.repo_tractor.lista:
                denumire=ele.denumire
                pret=ele.pret
                data=date.today()
                if sir in denumire and nr>=pret:
                    if ele.data>data:
                        print(ele.id,ele.denumire,ele.pret, ele.model,ele.data)
                    else:
                        print(ele.id,"*",ele.denumire,ele.pret, ele.model,ele.data)

        else:
            if sir=='' and nr!=-1:
                for ele in self.contr_tractor.repo_tractor.lista:
                    denumire=ele.denumire
                    pret=ele.pret
                    data=date.today()
                    if nr>=pret:
                        if ele.data>data:
                            print(ele.id,ele.denumire,ele.pret, ele.model,ele.data)
                        else:
                            print(ele.id,"*",ele.denumire,ele.pret, ele.model,ele.data)
            else:
                if sir!='' and nr==-1:
                    for ele in self.contr_tractor.repo_tractor.lista:
                        denumire=ele.denumire
                        pret=ele.pret
                        data=date.today()
                        if sir in denumire:
                            if ele.data>data:
                                print(ele.id,ele.denumire,ele.pret, ele.model,ele.data)
                            else:
                                print(ele.id,"*",ele.denumire,ele.pret, ele.model,ele.data)


    def undo(self):
        pass

    def optinui(self):

        """
            functia are rolul de a afisa optiunile puse la dispozitie utilizatorului
        """
        print("1.Adaugare\n"
              "2.Stergere\n"
              "3.Filtrare\n"
              "4.Undo\n"
              "5.Exit")
        
    def run(self):
        """
            functia are rolul de a rula consola 
            are un singur parametru self
        """
        optinui={1:self.adaugare,
                 2:self.stergere,
                 3:self.filtrare,
                 4:self.undo}
        self.contr_tractor.repo_tractor.adaugare_fisier()
        while True:
            self.optinui()
            op=int(input("Va rog sa introduceti o optiunie: "))
            if op==5:
                break
            try:
                optinui[op]()
            except ValueError() as er:
                print(er)
        
        
