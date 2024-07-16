from datetime import *
from entitati import *


class repository:
    def __init__(self, validator):
        self.validator=validator
        self.lista=[]

    def incarcare_fisier(self):
        f=open("date.txt","r")
        linie = f.readline()

        while linie!='':
            linie2=linie.strip()
            params=linie2.split(" ")

            data=params[0].split('.')
            zi=int(data[0])
            luna=int(data[1])
            an=int(data[2])

            a = date(an,luna,zi)

            ora=params[1].split(":")
            o=int(ora[0])
            m=int(ora[1])

            b = time(o,m)

            eve=eveniment(a,b,params[2])
            self.lista.append(eve)
            linie = f.readline()



    def sortare_afisare(self):
        self.lista.sort(key=lambda eveniment: (eveniment.data, eveniment.ora), reverse=True)
        for ele in self.lista:
            print(ele.data, " ",ele.ora," ", ele.descriere,"\n")
        
        