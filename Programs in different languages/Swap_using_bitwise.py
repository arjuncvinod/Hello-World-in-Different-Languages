#SWAPPING TWO NUMBERS USING BITWISE OPERETOR USING PYHTON

x = int(input("ENTER ONE NUMBER: "))
y = int(input("ENTER SECOND NUMBER: "))
print("ORIGINAL NUMBERS ARE",x,"AND",y)
# Swapping using Bitwise xor
x = x ^ y
y = x ^ y
x = x ^ y
 
print("SWAPPED NUMBERS ARE",x,"AND",y)
