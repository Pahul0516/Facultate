import os
from repository import *
from validator import *
from controller import *
from ui import *

class app:
    
    def main(self):

        emisiune_repo=repository(validator())
        emisiune_cont=controller(emisiune_repo)

        con=consola(emisiune_cont)
        con.run()
        


os.system("cls")
app=app()
app.main()
        
