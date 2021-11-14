print("MATRIX")
y=int(input(" Enter No of Rows : "))
x=int(input(" Enter No of Cols : "))

#creating matrix
m1=[[0 for i in range(0,x)] for j in range(0,y)]
m2=[[0 for i in range(0,x)] for j in range(0,y)]
m3=[[0 for i in range(0,x)] for j in range(0,y)]

print(" Enter Elements for First Matrix \n")
for i in range(0,x):
    for j in range(0,y):
        m1[j][i]=int(input(""))
        
print(" Enter Elements for Second Matrix \n")
for i in range(0,x):
    for j in range(0,y):
        m2[j][i]=int(input(""))
        m3[j][i]=m2[j][i]+m1[j][i]
print(" Result is \n")
for r in m3:
    print(r)
