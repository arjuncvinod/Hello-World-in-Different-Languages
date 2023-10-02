greeting: public(bytes[32]) # defining greeting state variable, just like Solidity

@public
def __init__(): # initialization function, same as Solidity's constructor function
    self.greeting = "Hello, World."
    
@public # function can be called internally and externally
@constant # function will not change state
def printGreeting() -> bytes[32]:
    return self.greeting

@public
def setGreeting(_greeting: bytes[32]): # a state changing function
    self.greeting = _greeting
