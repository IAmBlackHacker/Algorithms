from heapq import merge
def merge_sort(m):
    if len(m)<=1:
        retutn m
    middle=len(m)//2
    left=left[:middle]
    right=right[middle:]
    left=merge_sort(left)
    right=merge_sort(right)
    return list(merge(left,right))
        
