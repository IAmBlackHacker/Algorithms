def qsort(alist,first,last):
    if first<last:
        split=partition(alist,first,last)
        qsort(alist,first,split-1)
        qsort(alist,split+1,last)

def partition(alist,first,last):
    pivot=alist[last]
    index=first
    for i in range(first,last):
        if pivot>alist[i]:
            temp=alist[i]
            alist[i]=alist[index]
            alist[index]=temp
            index+=1
    temp=alist[last]
    alist[last]=alist[index]
    alist[index]=temp
    return index

n=int(input("Enter Number of Elements : "))
alist=[]
for i in range(0,n):
    alist.append(int(input()))
print(alist)
qsort(alist,0,len(alist)-1)
print(alist)
