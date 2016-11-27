import random

def mergeSort(alist):
    if len(alist)>1:
        print "splitting the array",alist
        mid = len(alist)//2  #the floor div
        lefthalf = alist[:mid]
        righthalf = alist[mid:]
        mergeSort(lefthalf)  #the recursive call after splitting
        mergeSort(righthalf) #the recursive call after splitting

        i=0
        j=0
        k=0


        while i < len(lefthalf) and j < len(righthalf):
            if  int(lefthalf[i])*10**len(righthalf[j])+int(righthalf[j]) < int(righthalf[j])*10**len(lefthalf[i])+int(lefthalf[j]): #custom comparison
                alist[k]=lefthalf[i]
                i=i+1
            else:
                alist[k]=righthalf[j]
                j=j+1
            k=k+1

        while i < len(lefthalf):  #to be used when index j is out of range of len(righthalf)
            alist[k]=lefthalf[i]
            i=i+1
            k=k+1

        while j < len(righthalf): #to be used when index i is out of range of len(lefthalf)
            alist[k]=righthalf[j]
            j=j+1
            k=k+1
        print "merging",alist



a = [random.randint(0,100) for c in range(5)]
print "before:",a
b = map(str, a)
print b
mergeSort(b)
print "new :",b