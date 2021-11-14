x=int(input("Enter no of cols for matrix1 : "))
y=int(input("Enter no of rows for matrix1 : "))
z=int(input("Enter no of cols for matrix2 : "))

m1=[i[:] for i in [[0]*x]*y]
m2=[i[:] for i in [[0]*z]*x]

print("Enter Elements for matrix1 : ")
for i in range(0,y):
    for j in range(0,x):
        m1[i][j]=int(input())
print("Enter Elements for matrix2 : ")
for i in range(0,x):
    for j in range(0,z):
        m2[i][j]=int(input())
    
m3=[[sum(m1[i][k]*m2[k][j] for k in range(0,x)) for i in range(0,y)] for j in range(0,z)]
print("Matrix 2")
for r in m1:
    print(r)
print("Matrix 2")
for r in m2:
    print(r)
print("Matrix 3")
for r in m3:
    print(r)
