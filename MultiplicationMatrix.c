#include <stdio.h>

int main() 
{
    int a[3][3],b[3][3],mul[3][3];
    int i,j,k;
    printf("Enter the first matrix elements\n");
    for(i=0;i<3;i++) 
	{
        for(j=0;j<3;j++) 
		{
            scanf("%d",&a[i][j]);
        }
    }
    printf("Enter the second matrix elements\n");
    for(i=0;i<3;i++) 
	{
        for(j=0;j<3;j++) 
		{
            scanf("%d",&b[i][j]);
        }
    }
    printf("\nFirst Matrix:\n");
    for(i=0;i<3;i++) 
	{
        for(j=0;j<3;j++) 
		{
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    printf("\nSecond Matrix:\n");
    for(i=0;i<3;i++) 
	{
        for(j=0;j<3;j++) 
		{
            printf("%d ",b[i][j]);
        }
        printf("\n");
    }
    for(i=0;i<3;i++) 
	{
        for(j=0;j<3;j++) 
		{
            mul[i][j]=0;
            for(k=0;k<3;k++) 
			{
                mul[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    printf("\nMatrix after multiplication\n");
    for(i=0;i<3;i++) 
	{
        for(j=0;j<3;j++) 
		{
           printf("%d ", mul[i][j]);
        }
        printf("\n");
    }
    return 0;
}

