class validator:
    def valideaza(self, emisiune):
        
        tipuri_nume=["Jurnal", "Reportaj", "Divertisment"]
        er1="Numele nu e bun"


        if emisiune.nume not in tipuri_nume:
            raise ValueError(er1)