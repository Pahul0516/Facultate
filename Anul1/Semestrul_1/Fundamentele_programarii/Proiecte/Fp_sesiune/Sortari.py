import os

os.system("cls")


def selection_sort(l):
    aux=0
    for i in range(0, len(l) - 1):
        ind = i
        for j in range(i+1, len(l)):
            if l[j]<l[ind]:
                ind = j      
        if i <ind:
            aux=l[ind]
            l[ind]=l[i]
            l[i]=aux 

    return l

def direct_selection_sort(l):
    aux=0
    for i in range(0, len(l)-1):
        for j in range(i+1,len(l)):
            if l[i]>l[j]:
                aux=l[j]
                l[j]=l[i]
                l[i]=aux
    return l

def Insertion_sort(l):

    for i in range (1,len(l)):
        for j in range(i,0,-1):
            if (l[j-1]>l[j]):
                aux=l[j-1]
                l[j-1]=l[j]
                l[j]=aux
            else:
                break

    return l

def bubble_sort(l):
    e_sortat=False
    while not e_sortat:
        e_sortat=True
        for i in range(len(l)-1):
            if l[i+1]>l[i]:
                aux=l[i+1]
                l[i+1]=l[i]
                l[i]=aux
                e_sortat=False

    return l


def partition(l,left,right):
    pivot=l[left]
    i=left
    j=right
    while i!=j:
        while l[j]>pivot and i<j:
            j-=1
        l[i]=l[j]
        while l[i]<pivot and i<j:
            i+=1
        l[j]=l[i]
    l[i]=pivot
    return i

def quick_sort(l,left,right):
    pivot_location=partition(l,left,right)
    if left<pivot_location-1:
        quick_sort(l,left,pivot_location-1)
    if pivot_location+1<right:
        quick_sort(l,pivot_location+1,right)
    
    return l


def merge(l,start,end,mij):
    c=[]
    i=start
    j=mij+1
    while i<=mij and j<=end:
        if l[i]<l[j]:
            c.append(l[i])
            i+=1
        else:
            c.append(l[j])
            j+=1

    while i<=mij:
        c.append(l[i])
        i+=1

    while j<=end:
        c.append(l[j])
        j+=1  

    j=0
    for i in range(start,end+1):
        l[i]=c[j]
        j+=1

def merge_sort(l, start, end):
    if end-start<=0:
        return
    mij=(end+start)//2
    merge_sort(l,start,mij)
    merge_sort(l,mij+1,end)
    merge(l,start,end,mij)

    return l

def cautare_binara(l,ele):
    gasit=False
    start=0
    end=len(l)-1
    while(end-start>=0):
        mij=(start+end)//2
        if l[mij]==ele:
            gasit=True
            break
        else:
            if l[mij]<ele:
                start=mij+1
            else:
                end=mij-1

        
        
    if gasit==True:
        print("Gasit")
    else:
        print("Nu e")

def cautare_binara_rec(l,ele,start,end):
    mij=(end+start)//2
    if end-start<0:
        return False
    else:
        if ele == l[mij]:
            return True
        else: 
            if l[mij]<ele:
                return cautare_binara_rec(l,ele,mij+1,end)
            else:
                return cautare_binara_rec(l,ele,start,mij-1)


l=[7,2,3,0,1,5,6,4]
l2=[1,4,2,6,1,0]
print(quick_sort(l,0,len(l)-1))