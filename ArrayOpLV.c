#include<stdio.h>
int insert(int a[5],int pos,int el){
	if(pos==5){
		printf("Error: Array Full");
	}
	else{
		a[++pos]=el;
	}
	return pos;
}

void search(int a[5],int pos,int el){
	int i,flag=0;
	if(pos==-1){
		printf("Error: no elements in array");
	}
	else{
		for(i=0;i<=pos;i++){
			if(a[i]==el){
				flag=1;
			}
		}
		if(flag==1){
			printf("%d found in Array",el);
		}
		else{
			printf("Error: %d not found",el);
		}
	}
}

int del(int a[5],int pos){
	if(pos==-1){
		printf("Error: no elements in array");
	}
	else{
		printf("%d deleted from array",a[pos--]);
	}
	return pos;
}

int sort(int a[5],int pos){
	int i,j,e;
	if(pos==-1){
		printf("Error: no elements in array");
	}
	else{
		for(i=0;i<pos;i++){
			for(j=i+1;j<=pos;j++){
			if(a[j]<a[i]){
				e=a[i];
				a[i]=a[j];
				a[j]=e;
			}
		}
		}
		printf("Array elements after sorting:");
		for(i=0;i<=pos;i++){
			printf("%d\t",a[i]);
		}
	}
	return pos;
}

void display(int a[5],int pos){
	int i;
	if(pos==-1){
		printf("Error: no elements in array");
	}
	else{
		for(i=0;i<=pos;i++){
			printf("%d\t",a[i]);
		}
	}
}
int main(){
	int ch=1,el,a[5],pos=-1;
	while(ch){
		printf("\n0.Exit\n1.Insert\n2.Search\n3.Delete\n4.Sort\nSelect one operation: ");
		scanf("%d",&ch);
		switch(ch){
			case 0: return;break;
			case 1:printf("Enter element to insert: ");
			scanf("%d",&el);
			pos=insert(a,pos,el);
			break;
			case 2:printf("Enter element to search: ");
			scanf("%d",&el);
			search(a,pos,el);
			break;
			case 3:pos=del(a,pos);
			break;
			case 4:pos=sort(a,pos);
			break;
			case 5: display(a,pos);break;
			default: printf("Error:Invalid Choice");	
			break;
		}
	}
	return 0;
}
