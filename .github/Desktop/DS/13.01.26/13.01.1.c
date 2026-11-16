#include<stdio.h>
int main(){
	int a=10,b=20;
	printf("Before swap :");
	printf("%d %d",a,b);
	swap(&a,&b);
	printf("after swap :");
	printf("%d %d",a,b);
}
int swap(int *x,int *y)
{
	int t;
	t=*x;
	*x=*y;
	*y=t;
}
