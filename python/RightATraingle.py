index=dict()
for d in range(1,10000):
    if d%2==0:
        dif=d
    else:
        dif=d*2
    for i in range(d+dif,10000,dif):
         per=i+i*i//d
         pro=i* ((i**4-d**4)//(4*d*d))
         if per>3500:
             break
         try:
             if index[per]<pro:
                 index[per]=pro
         except:
             index[per]=pro
#print(index)
