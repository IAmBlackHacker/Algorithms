def max_heapify(A,i):
    left=2*i+1
    right=2*i+2
    if left<A.__len__() and A[left]>A[i]:
        largest=left
    else:
        largest=i
    if right<A.__len__() and A[right]>A[largest]:
        largest=right
    if largest!=i:
        (A[largest],A[i])=(A[i],A[largest])
        max_heapify(A,largest)
def build_max_heap(A):
    for i in range(A.__len__()//2-1,-1,-1):
        max_heapify(A,i)
B=[]
def heapsort(A):
    build_max_heap(A)
    for i in range(A.__len__()-1,-1,-1):
        (A[0],A[i])=(A[i],A[0])
        B.append(A.pop())
        max_heapify(A,0)
            
A=[1,2,4,2,5,6,4]
heapsort(A)
print(B)
