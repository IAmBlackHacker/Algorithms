def amicable(x,y):
    sumx=0
    sumy=0
    for i in range(1,x):
        if x%i==0:
            sumx+=i
    for i in range(1,y):
        if y%i==0:
            sumy+=i
    return sumx==y and sumy==x

n1=int(input("Enter Number1 : "))
n2=int(input("Enter Number1 : "))
if amicable(n1,n2):
    print("Numbers are Amicable")
else:
    print("Numbers are not Amicable")
            
