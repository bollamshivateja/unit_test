#include<stdio.h>
int main(){
	int a[2][2]={{10,20},{30,40}},i,j;
	a[1][1]=100;
	for(i=0;i<2;i++){
		for(j=0;j<2;j++){
			printf("%d\t",a[i][j]);
		}printf("\n");
	}
	printf("%d",sizeof(a));
	int length=sizeof(a)/sizeof(a[0][0]);
	printf("%d\n",length);
}

