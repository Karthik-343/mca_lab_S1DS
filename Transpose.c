#include <stdio.h>

int main() 
{
    int a[3][3],tran[3][3];
    int i,j;
    printf("Enter the matrix elements\n");
    for(i=0;i<3;i++) 
	{
        for(j=0;j<3;j++) 
		{
            scanf("%d",&a[i][j]);
        }
    }
    printf("\nThe Matrix\n");
    for(i=0;i<3;i++) 
	{
        for(j=0;j<3;j++) 
		{
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    printf("\nTranspose\n");
    for(i=0;i<3;i++)
    {
    	for(j=0;j<3;j++)
    	{
    		tran[i][j]=a[j][i];
    		printf("%d ",tran[i][j]);
		}
		printf("\n");
	}
}
