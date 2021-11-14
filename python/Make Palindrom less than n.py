
def MakePalin(n,s,e):
    if n[s]!=n[e]:
        if n[s]<n[e]:
            n[e]=n[s]
        else:
            n[e]=n[s]
            e1=e-1
            while 1:
                n[e1]-=1
                if n[e1]==-1:
                    n[e1]=9
                    e1-=1
                    continue
                break
            s-=1
            e+=1
    if s+1<e:
        MakePalin(n,s+1,e-1)
               
n=list(map(int,input()))
print(MakePalin(n,0,len(n)-1),n)

# "".join(map(str,n))
