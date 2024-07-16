import os
from ui import *
from contorller import *
from repository import *
from validare import *
os.system("cls")


class app:
    def main(self):
        repo_tractor=repository(validator)
        contr_tractor=controller(repo_tractor)

        con=consola(contr_tractor)
        con.run()

app=app()
app.main()

