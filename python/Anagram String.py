def anagram(s1,s2):
    if(len(s1)==len(s2)):
        d=dict()
        for i in s1:
            d[i]=0
        #or d={}.formkeys(s1,0)
        for i in s1:
            d[i]+=1
        for i in s2:
            try:
                if d[i]==0:
                    return False
                d[i]-=1
            except KeyError:
                return False
        return True
    return False
s1=str(input("Enter String1 : "))
s2=str(input("Enter String2 : "))
if anagram(s1,s2):
    print("String are Anagram")
else:
    print("String are not Anagram")
