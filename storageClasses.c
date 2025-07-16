#include<stdio.h>
int a=10; //global

void static1(){
	static int s=1; //static
	s++;
	printf("\nstatic variable value is %d",s);
}

void register1(){
	register int r=5; //register
	printf("\nRegister variable value is %d",r);
}
int main(){
	int b=11; //local
	printf("%d %d",a,b);
	static1();
	static1();
	static1();
	register1();
	return (0);
}
