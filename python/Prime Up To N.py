import math
n=int(input("Enter Number : "))
n=list(range(2,n+1))
for i in n:
    print(i)
    k=2
    while i*k<=n[-1]:
        try:
            n.remove(i*k)
        except:
            k+=1
            continue
        k+=1
with open("#35.py","w") as f:
    f.write(str(n))
