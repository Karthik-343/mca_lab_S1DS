#include <stdio.h>

int main() 
{
    int a[2][2],b[3][3];
    int i,j,det2,det3;
    printf("Enter the 2x2 matrix elements\n");
    for(i=0;i<2;i++) 
	{
        for(j=0;j<2;j++) 
		{
            scanf("%d",&a[i][j]);
        }
    }
    printf("Enter the 3x3 matrix elements\n");
    for(i=0;i<3;i++) 
	{
        for(j=0;j<3;j++) 
		{
            scanf("%d",&b[i][j]);
        }
    }
    printf("\n2x2 Matrix:\n");
    for(i=0;i<2;i++) 
	{
        for(j=0;j<2;j++) 
		{
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    printf("\n3x3 Matrix:\n");
    for(i=0;i<3;i++) 
	{
        for(j=0;j<3;j++) 
		{
            printf("%d ",b[i][j]);
        }
        printf("\n");
    }
    det2=(a[0][0]*a[1][1])-(a[0][1]*a[1][0]);
    printf("\nDeterminant of 2x2 matrix: %d\n",det2);
    
    det3=b[0][0] * (b[1][1] * b[2][2] - b[1][2] * b[2][1])
        -b[0][1] * (b[1][0] * b[2][2] - b[1][2] * b[2][0])
        +b[0][2] * (b[1][0] * b[2][1] - b[1][1] * b[2][0]);
    printf("\nDeterminant of 3x3 matrix: %d",det3);
    return 0;
}
