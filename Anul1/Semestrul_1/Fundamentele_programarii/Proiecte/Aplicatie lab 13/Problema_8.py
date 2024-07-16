import os
os.system('cls')


def afisare(lista):
    prev=[]
    prev.append(0)
    prev=prev+lista
    prev.append(0)
    for i in range(0,len(prev)):
        print(prev[i], end=' ')
    print("\n")
def cond(lista):
    prev=[]
    prev.append(0)
    prev=prev+lista
    prev.append(0)

    for i in range(0,len(prev)-1):
        if not(abs(prev[i+1]-prev[i])==1 or abs(prev[i+1]-prev[i])==2):
            return False
    return True


def bkt(lista, n):

    """
        spatiul de cautare este A*A*A unde A={-1,0,1}
    """
    k=0 # indice pentru a parcurge candidatii
    lista.append(-2) # pleci cu elementele de la unu mai mic decat cel mai mic din multimea A (ex: -1)
    while k!=-1: # atata timp cat inca poti sa generezi candidat
        if lista[k]<1: # verifici daca nu s-a ajuns la elementul maxim din multimea A (ex: 2)
            lista[k]+=1
            if k+1==n: # daca candidatul generat are deja lungimea necesara
                if cond(lista): # verificam conditia din cerinta
                    afisare(lista) # afisare solutie candidat
            else:
                k+=1 # mai adaugam un element la candidat 
                lista.append(-2)
        else:
            lista.pop() # revenim la elementul anterior din candidat
            k-=1

def bkt_rec(lista,n):
    if len(lista)==n: # daca candidatul generat are deja lungimea necesara
        if cond(lista):  # verificam conditia din cerinta
            afisare(lista) # afisare solutie candidat
        return
    
    lista.append(-2) # pleci cu elementele de la unu mai mic decat cel mai mic din multimea A (ex: -1)
    for i in range (-1,2):
        lista[-1]=i # adaugare elemente in candidati
        bkt_rec(lista,n)
    lista.pop() # revenim la elementul anterior din candidat

lista=[]
n = int(input("Va rog sa introduceti un numar: "))
bkt_rec(lista,2*n-1)
