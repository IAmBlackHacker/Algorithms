def gcd(a,b):
    a=a%b
    if a==0:
        return b
    else:
        return gcd(b,a)
print(gcd(9,54))
    
