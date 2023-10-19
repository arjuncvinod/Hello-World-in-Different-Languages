# Recursive imlementation of Euclid's algorithm in Python

def gcd(x,y):
    larger = max(x,y)
    smaller = min(x,y)

    remainder = larger % smaller

    if(remainder == 0):
        return(smaller)

    if(remainder != 0):
        return(gcd(smaller,remainder))

print(gcd(123,25))
