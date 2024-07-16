import os

os.system('cls')

def afisare(lista):
    for ele in lista:
        g.write(str(ele)+' ')
    g.write('\n')

def cond(lista,k):
    for i in range (0, k):
        if lista[i]==lista[k]:
            return 0
    return 1

def bkt(lista, n):
    k=0
    lista.append(0)
    while k!=-1:
        lista[k]+=1
        if lista[k]<=n:
            if cond(lista, k)==1:
                if k+1==n:
                    afisare(lista)
                else:
                    k+=1
                    lista.append(0)
        else:
            lista.pop()
            k-=1

def bkt_rec(lista, n):
    if len(lista)==n:
        afisare(lista)
        return
    lista.append(0)
    for i in range(1, n+1):
        lista[-1]=i
        index=len(lista)-1
        if cond(lista, index) == 1:
            bkt_rec(lista, n)
    lista.pop()


f=open("citire.txt", "r")
g=open("afisare.txt", "w")

n=int(f.read())
lista=[]
k=0
bkt_rec(lista, n)


f.close()
g.close()
