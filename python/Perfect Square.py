import math
n=int(input("Enter Number : "))
m=int(math.sqrt(n))
if m*m==n:
    print("Is a Perfect Square")
else:
    print("Is not a Perfect Square")
