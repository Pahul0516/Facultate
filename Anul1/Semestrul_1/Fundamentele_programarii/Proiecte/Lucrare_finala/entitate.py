class tractoare:
    def __init__(self,id,denumire,pret,model,data):
        self.id=id
        self.denumire=denumire
        self.pret=pret
        self.model=model
        self.data=data
    
    def get_id(self):
        """
            functia are rolul de a returna id-ul
            are un singur parametru self
        """
        return self.id
    
    def get_denumire(self):
        """
            functia are rolul de a returna denumirea
            are un singur parametru self
        """
        return self.denumire
    
    def get_pret(self):
        """
            functia are rolul de a returna pretul
            are un singur parametru self
        """
        return self.pret
    
    def get_model(self):
        """
            functia are rolul de a returna modelul
            are un singur parametru self
        """
        return self.model
