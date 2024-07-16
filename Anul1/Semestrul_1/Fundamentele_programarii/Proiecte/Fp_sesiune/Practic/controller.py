class controller():
    def __init__(self,repo):
        self.repo=repo

    def stergere(self, nume, tip):
        if self.repo.cautare_componenta(nume)==True and  self.repo.cautare_componenta(tip)==True:
            self.repo.stergere(nume,tip)
        else:
            raise ValueError("Nu exista")
    def actualizare(self, nume, tip,durata,descriere):
        if self.repo.cautare_componenta(nume)==True and  self.repo.cautare_componenta(tip)==True:
            self.repo.actualizare(nume,tip,durata,descriere)
        else:
            raise ValueError("Nu exista")