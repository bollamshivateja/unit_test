#include<stdio.h>
int main(){
	int a=10,b=20;
	printf("Before swapping:");
	printf("%d %d",a,b);
	swap(&a,&b);
	printf("After swapping:");
	printf("%d %d",a,b);
}
int swap(int *x,int *y)
{
	int t;
	t=*x;
	*x=*y;
	*y=t;
}

