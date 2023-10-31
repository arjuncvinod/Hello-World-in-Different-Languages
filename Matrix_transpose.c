#include<stdio.h>
int main()
{
    int i,j,n,m;
    printf("Enter the rows of matrix ");
    scanf("%d",&n);
    printf("Enter the number of columns ");
    scanf("%d",&m);

    int arr[n][m];
    printf("Enter the elements of the matrix\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    printf("The transpose is\n");
    for(j=0;j<m;j++)
    {   printf("\n");
        for(i=0;i<n;i++)
        {
            printf("%d\t",arr[i][j]);
        }
    }
    return 0;
}
