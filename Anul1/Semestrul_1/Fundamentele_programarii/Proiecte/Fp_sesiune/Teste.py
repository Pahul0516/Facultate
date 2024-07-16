import os
os.system("cls")

def selection_sort(l):
    for i in range(0,len(l)-1):

        index=i

        for j in range(i+1,len(l)):
            if l[index]>l[j]:
                index=j
 
        if i<index:
            aux=l[index]
            l[index]=l[i]
            l[i]=aux
    return l

def insertion_sort(l):
    for i in range(0,len(l)-1):
        for j in range(i+1,0,-1):
            if l[j-1]>l[j]:
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
        for i in range(0,len(l)-1):
            if l[i]>l[i+1]:
                aux=l[i]
                l[i]=l[i+1]
                l[i+1]=aux
                e_sortat=False

    return l

def merge(l,start,end,mij):
    i=start
    j=mij+1
    c=[]
    while i<=mij and j<=end:
        if l[i]<l[j]:
            c.append(l[i])
            i+=1
        if l[i]>l[j]:
            c.append(l[j])
            j+=1

    while i<=mij:
        c.append(l[i])
        i+=1

    while j<=end:
        c.append(l[j])
        j+=1

    j=0
    for i in range (start,end+1):
        l[i]=c[j]
        j+=1


def merge_sort(l,start,end):
    if end-start<=0:
        return 
    mij=(end+start)//2
    merge_sort(l,start,mij)
    merge_sort(l,mij+1,end)
    merge(l,start,end,mij)

    return l


def cautare_binara(l, ele,start,end):
    ok=False
    while end-start>=0:
        mij=(end+start)//2
        if l[mij]==ele:
            ok=True
            break
        else:
            if l[mij]<ele:
                start=mij+1
            else:
                end=mij-1
    if ok==True:
        print("Gasit")
    else:
        print("Nu e")

def cautare_binara_rec(l, ele,start,end):
    mij=(end+start)//2
    if end-start<0:
        return 0
    else:
        if l[mij]==ele:
            return 1
        else:
             if l[mij]<ele:
                 return cautare_binara_rec(l,ele, mij+1,end)
             else:
                 return cautare_binara_rec(l,ele, start,mij-1)


def div_et_imp(l):
    if len(l)==1:
        if l[0]<0:
            return 1
        else:
            return 0
    else:
        mij=len(l)//2
        st=div_et_imp(l[:mij])
        dr=div_et_imp(l[mij:])
        return st+dr
    
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

l=[- 1,2,3,-4,-5,6,-7]
print(quick_sort(l,0,len(l)-1))