"""find primes"""
def prime(cad,ipr=3):
    for n in cad:
        if n%ipr==0 and ipr!=n:
            cad.remove(n)
            print(n)
    try:
        ipr=cad[cad.index(ipr)+1]
        return prime(cad,ipr)
    except :
        return cad

def primeupto(n):
    cad=list(range(3,n+1,2))
    cad.insert(0,2)
    return prime(cad)

n=int(input("Enter int:"))
pr=primeupto(n)
