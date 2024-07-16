import os
from ui import *
from contorller import *
from repository import *
from validare import *

os.system("cls")

class app:
    def main(self):

        repo_date=repository(validator)
        contr_data=contoreller(repo_date)

        con=consola(contr_data)
        con.run()

app=app()
app.main()