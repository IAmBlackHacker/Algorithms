class parent(object):
    def __init__(self):
        print("parent class constructor")
    def display(self):
        print("parent class method")
class child(parent):
    def __init__(self):
        print("child class constructor")
    def display(self):
        print("child class method")
        parent.display(self)   #required self
        super(child,self).display() #not requied self
p=parent()
c=child()
c.display()
