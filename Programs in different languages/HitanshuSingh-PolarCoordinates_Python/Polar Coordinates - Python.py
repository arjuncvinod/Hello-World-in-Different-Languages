#Program to get the polar coordinates of any complex number, input by the user.

#Take input from user.
c=complex(input("Enter any complex number :"))

#Import cmath
import cmath

#Store the absolute value of complex number
j=abs(c)

#Store the phase of complex number
f=cmath.phase(c)

#Print
print("The polar coordinates of the given complex number, are :","(",j,",",f,")")
