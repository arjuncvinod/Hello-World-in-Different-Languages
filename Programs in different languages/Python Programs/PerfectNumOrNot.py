# whether the number is perfect number or not 
# 6 is a perfect number - factors of 6 is 1+2+3= 6


num= int(input("enter the number "))
sum=0
if (num):
    for i in range(1,num//2+1):
        if(num%i==0):
            sum=sum+i
if(num==sum):
    print(f"{num} is a perfect number")
else:
    print(f"{num} not a perfect number ")
