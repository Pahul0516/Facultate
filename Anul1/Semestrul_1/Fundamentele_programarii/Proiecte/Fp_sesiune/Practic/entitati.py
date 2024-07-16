

class emisiune:
    def __init__(self, nume,tip,durata,descriere):
        self.nume=nume
        self.tip=tip
        self.durata=durata
        self.descriere=descriere
        self.blocat=0

    def get_nume(self):
        return self.nume
    
    def get_tip(self):
        return self.tip
    
    def get_durata(self):
        return self.durata
    
    def get_descriere(self):
        return self.descriere
    

    def set_nume(self, nume):
        self.nume = nume

    def set_tip(self, tip):
        self.tip = tip

    def set_durata(self, durata):
        self.durata = durata

    def set_descriere(self, descriere):
        self.descriere = descriere


    
