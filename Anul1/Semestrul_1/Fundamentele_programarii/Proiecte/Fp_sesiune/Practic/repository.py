from entitati import *

class repository:
    def __init__(self,validator):
        self.lista=[]
        self.validator=validator

    def adaugare_fisier(self):
        f=open("emisiuni.txt", "r")
        linie = f.readline()
        while linie!='':

            linie.strip("\n")
            params = linie.split(" ")
            nume=params[0]
            tip=params[1]
            durata=params[2]
            descriere=""
            for i in range(3,len(params)):
                descriere=descriere+params[i]+" "

            e=emisiune(nume,tip,durata,descriere)
            self.validator.valideaza(e)
            self.lista.append(e)

            linie = f.readline()

    def stergere(self,nume,tip):
        for ele in self.lista:
            if ele.nume==nume:
                self.lista.remove(ele)
                break

        f = open("emisiuni.txt", "w")
        for ele in self.lista:
            f.write(ele.nume)
            f.write(" ")
            f.write(ele.tip)
            f.write(" ")
            f.write(ele.durata)
            f.write(" ")
            f.write(ele.descriere)
            f.write("\n")
        
        f.close()

    def actualizare(self,nume,tip,durata,descriere):
        for ele in self.lista:
            if ele.nume==nume:
                ele.durata=durata
                ele.descriere=descriere
                break

        f = open("emisiuni.txt", "w")
        for ele in self.lista:
            f.write(ele.nume)
            f.write(" ")
            f.write(ele.tip)
            f.write(" ")
            f.write(str(ele.durata))
            f.write(" ")
            f.write(ele.descriere)
            f.write("\n")
        
        f.close()


    def cautare_componenta(self, componenta):
        gasit=False
        for ele in self.lista:
            if ele.nume==componenta:
                return True
            if ele.tip==componenta:
                return True

    def size(self):
        return len(self.lista)

            


