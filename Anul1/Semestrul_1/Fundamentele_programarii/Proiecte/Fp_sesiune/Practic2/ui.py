class consola:
    def __init__(self, cont_data):
        self.cont_data=cont_data

    def afisare_optinui(self):
        print("1.Adaugare\n"
              "2.Tiparire_criteriu\n"
              "3.Export\n"
              "4:Exit")

    def adaugare(self):
        pass

    def Tiparire_criteriu(self):
        pass
    
    def Export(self):
        pass

    def run(self):
        optiuni={1:self.adaugare,
                 2:self.Tiparire_criteriu,
                 3:self.Export}
        
        self.cont_data.repo_date.incarcare_fisier()
        self.cont_data.repo_date.sortare_afisare()

        while True:
            self.afisare_optinui()

            try:
                op=int(input("Va rog sa introduceti o optine: "))
                if op==4:
                    break
                optiuni[op]()
            except ValueError as er:
                print(er)
        