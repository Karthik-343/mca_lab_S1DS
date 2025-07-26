#include<stdio.h>

int main(){
	int a[10],n,i,b;
	int flag=0;
	printf("enter the limit\n");
	scanf("%d",&n);
	printf("enter the elements\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("enter the value to be found\n");
	scanf("%d",&b);
	for(i=0;i<n;i++)
	{
		if (a[i]==b)
		{
			printf("element found at postion %d\n",i);
			flag++;			
		}
	}
	if (flag==0)
	{
		printf("element not found");
	}
	printf("\nTotal occurences= %d",flag);
	
}
