#Code contributed by pree-04
#A simple python program to implement the concept of inheritance
#The Base class
class Animal:
    def __init__(self, name):
        self.name = name

    def speak(self):
        pass

#Derived class 1 (Single Inheritance)
class Dog(Animal):
    def speak(self):
        return f"{self.name} says Woof!"

#Derived class 2 (Single Inheritance)
class Cat(Animal):
    def speak(self):
        return f"{self.name} says Meow!"

#Derived class 3 (Multiple Inheritance)
class Parrot:
    def __init__(self, name):
        self.name = name

    def speak(self):
        return f"{self.name} says Squawk!"

class PetCat(Animal, Parrot):
    def speak(self):
        return f"{self.name} is a cat and {super().speak()}"

if __name__ == "__main__":
    dog = Dog("Buddy")
    cat = Cat("Whiskers")
    pet_cat = PetCat("Tommy")

    print(dog.speak())  # Output: Buddy says Woof!
    print(cat.speak())  # Output: Whiskers says Meow!
    print(pet_cat.speak())  # Output: Tommy is a cat and Tommy says Squawk!
