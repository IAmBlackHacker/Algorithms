def MergeSort(seq):
    mid=len(seq)//2
    lft,rgt=seq[:mid],seq[mid:]
    if len(lft)>1:
        lft=MergeSort(lft)
    if len(rgt)>1:
        rgt=MergeSort(rgt)
    res=[]
    while lft and rgt:
        if lft[0]<=rgt[0]:
            res.append(lft.pop(0))
        else:
            res.append(rgt.pop(0))
    return res+(lft or rgt)

seq=[12,45,7,78,14,0,12,1,85,79,2]
print(MergeSort(seq))
