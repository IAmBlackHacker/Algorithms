class LengthError(Exception):
    def __init__(self,length,limit):
        Exception.__init__(self)
        self.length=length
        self.limit=limit

try:
    st=str(input("Enter String : "))
    if len(st)<8:
        raise LengthError(len(st),8)
except ValueError:
    print("Enter Wrong Value")
except LengthError as ex:
    print("You Enter String of lenght {} try atlist {} character...".format(ex.length,ex.limit))
else:
    print("Try Proper Input")
