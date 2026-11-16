#include<stdio.h>
int main(){
	int a[10];
	int i,n,s,found=0;
	printf("Enter the value of n:");
	scanf("%d",&n);
	printf("Enter the values:");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	printf("Elements:");
	for(i=0;i<n;i++){
		printf("\na[%d]=%d",i,a[i]);
	}
	printf("\nEnter the value of search:");
	scanf("%d",&s);
	for(i=0;i<n;i++){
		if(s==a[i]){
		
		found=1;
		}else{
			found=0;
		}
	}
	if (found==1){
		printf("element found");
	}else{
		printf("element not found");
	}
}
