#include<stdio.h>
int main(){
	int a[]={10,20,30,40,50};
	printf("%d",sizeof(a));
	int length=sizeof(a)/sizeof(a[0]);
	printf("%d",length);
}
