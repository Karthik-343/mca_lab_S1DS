#include<stdio.h>

int a[10],n;
void read()
{
	int i;
	printf("enter the limit\n");
	scanf("%d",&n);
	printf("\nenter the elements\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
}

void disp()
{
	int i;
	printf("the elements are\n");
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
}

void sort()
{
    int i, j, temp;
    for(i = 0; i < n - 1; i++)
    {
        for(j = 0; j < n - i - 1; j++)
        {
            if(a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    
}

int main(){
	read();
	printf("\nArray Before Sorting\n");
	disp();
	sort();
	printf("\n\nArray After Sorting\n");
	disp();
}
