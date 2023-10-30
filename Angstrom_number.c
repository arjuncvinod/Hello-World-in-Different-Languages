#include<stdio.h>
int main()
{int a,sum,i,t;
printf("Enter the number ");
scanf("%d",&a);
sum=0;t=a;
while(a>0)
{i=a%10;
a=a/10;
sum=sum+(i*i*i);
}
if(sum==t)
{printf("The number is an angstrom number");}
else {printf("The number is not an angstrom number");}
}