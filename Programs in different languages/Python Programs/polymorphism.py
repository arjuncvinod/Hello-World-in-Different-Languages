class parent:
    def __init__(self, name, grade) :
        self.name = name
        self.grade = grade

    def display(self):
        print("Parent Display method " )
        print("Name : ", self.name)
        print("Grade :", self.grade)

    def __del__(self):
        print("Parent Destructor")


class child(parent):
    def __init__(self, name, grade) :
        parent.__init__(self, name, grade)

    def show(self):
        print("Show method : ")
        parent.display(self)

    def __del__(self):
        print("Child Destructor")

s1 = child("xyz", 'A')

s1.display()

s1.show()

del(s1)

    

    
