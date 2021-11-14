def termf(n):
    if n==1:
        return 2
    if n==2:
        return 8
    else:
        #
        return 4*termf(n-1)+termf(n-2)

n=int(input("Enter Term: "))
print(termf(n))
