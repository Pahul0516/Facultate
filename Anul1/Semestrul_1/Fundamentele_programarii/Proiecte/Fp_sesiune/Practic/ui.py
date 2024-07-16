class consola:
    def __init__(self, emisiune_cont):
        self.emisiune_cont=emisiune_cont

    def stergere(self):
            nume=input("Va rog sa introduceti numele emisiunii: ")
            tip=input("Va rog sa introduceti tipul: ")
            self.emisiune_cont.stergere(nume,tip)

    def actualizare(self):
            nume=input("Va rog sa introduceti numele emisiunii: ")
            tip=input("Va rog sa introduceti tipul: ")
            durata=int(input("Va rog sa introduceti durata: "))
            descriere=input("Va rog sa introduceti descriere: ")
            self.emisiune_cont.actualizare(nume,tip,durata,descriere)


    def tiparire(self):
        pass

    def blocare(self):
        pass

    def afisare_opriuni(self):
        print("1.Stergere \n"
              "2.Actualizare \n"
              "3.Tiparire \n"
              "4.Blocare \n"
              "5.Exit")


    def run(self):

        try:
            self.emisiune_cont.repo.adaugare_fisier()
        except ValueError as er:
            print(er)
        
        optinui={1:self.stergere,
                 3:self.tiparire,
                 2:self.actualizare,
                 4:self.blocare}
        while(True):
            self.afisare_opriuni()
            op=int(input("Va rog sa introduceti una dintre optinuiile de mai sus: "))
            if op==5:
                break
            try:

                optinui[op]()

            except ValueError as er:
                print(er)