#include <stdio.h>
int main()
/* {
    int a, i, x=0;
    printf("Enter the number to check ");
    scanf("%d", &a);
    if (a == 0 || a == 1)
        printf("\nNumber is neither prime nor composite ");
    for (i = 1; i <= a; i++)
    {
        if (a%i==0){
            x++;
            }
    }
    if(x==2)
    printf("The number is prime");
    else
    printf("The number is composite");
    return 0;
} */
{
    int a,i;
    printf("Enter the number ");
    scanf("%d", &a);
    if (a == 0 || a == 1)
        printf("\nNumber is neither prime nor composite ");
    for(i=2;i<a;i++)
    {if(a%i==0)
    {printf("The number is composite");
    break;}
    
    }
    if (i==a) {
        printf("The number is prime");
    }

    }
