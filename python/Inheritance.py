class parent:
    def __init__(self,a,b):
        self.a=a
        self.b=b
    def show(self):
        print(self.a+self.b)
class child(parent):
    def __init__(self,num,a,b):
        parent.__init__(self,a,b)
        self.num=num
    def show(self):
        print(self.a+self.b,self.num,sep="=")

a=parent("jnv","Gondia")
b=child(15,"ram","laal")
a.show()
b.show()
