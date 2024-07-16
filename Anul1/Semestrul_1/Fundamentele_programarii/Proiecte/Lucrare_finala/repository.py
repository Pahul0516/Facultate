from datetime import *
from entitate import *


class repository:
    def __init__(self,validator):
        self.validator=validator
        self.lista=[]

    def adaugare(self,entitate):
        """
            functia are 2 parametrii, self si o entitate
            are rolul de a adauga entitatea intr-o lista
        """
        self.lista.append(entitate)

    def stergere(self, c):
        """
            functia are rolul de a cauta si de a sterge tractoarele a caror pret contine cifra c
            2 parametrii 
            c= int
            self
            functia returneaza numarul de tractoare sterse

        """
        contor=0
        de_eliminat=[]
        for ele in self.lista:
            pret=ele.pret
            ok=0
            while pret!=0:
                uc=pret%10
                pret=pret//10
                if uc==c:
                    ok=1
                
            if ok==1:

                de_eliminat.append(ele)
                contor+=1
        
        for ele in de_eliminat:
            self.lista.remove(ele)

        return contor
    
        

    def adaugare_fisier(self):
        """
            functia are rolul de a citi datele din fisierul tractoare.txt si 
            are rolul de a crea entitatea tractor pe care sa o adauge in lista

            are  un singur parametriu - self
            nu returneaza nimic
        """

        f=open("tractoare.txt","r")
        linie=f.readline()
        while linie!='':
            params=linie.split(" ")
            id=int(params[0])
            denumire=params[1]
            pret=int(params[2])
            model=params[3]
            
            params2=params[4].split(".")
            zi=int(params2[0])
            luna=int(params2[1])
            an=int(params2[2])

            d=date(an,luna,zi)

            tractor=tractoare(id,denumire,pret,model,d)
            self.lista.append(tractor)

            linie=f.readline()
        
        f.close()

    def afisare_fisier(self):

        """
            are un singur parametru 
            are rolul de a afisa toate datele in  fisier
        """
        f=open("tractoare.txt", "w")
        for ele in self.lista:
            afis=str(ele.id)+" "+str(ele.denumire)+" "+ str(ele.pret)+" "+str(ele.model)+" "+str(ele.data.day)+'.'+str(ele.data.month)+'.'+str(ele.data.year)+"\n"
            f.write(afis)
        f.close()


    def size(self):
        return len(self.lista)