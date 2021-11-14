n=int(input("Enter Number in Decimal : "))
dec=0
i=0
while n:
    dec+=((n%10)<<i)
    i+=1
    n=n//10
print("Decimal Value is : ",dec)
