#include<stdio.h>
int main()
{
	int a[3][3],b[3][3],sum[3][3],diff[3][3],i,j;
	printf("Enter the first array elements\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	printf("Enter the second array elements\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			scanf("%d",&b[i][j]);
		}
	}
	printf("\nFirst Array\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
	printf("\nSecond Array\n");
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
			sum[i][j]= a[i][j] + b[i][j];
		}
	}
	printf("\nAfter Addition\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%d ",sum[i][j]);
		}
		printf("\n");
	}
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			diff[i][j]=a[i][j]-b[i][j];
		}
	}
	printf("\nAfter Subtraction\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%d ",diff[i][j]);
		}
		printf("\n");
	}
	return 0;
}
