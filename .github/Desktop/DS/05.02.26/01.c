#include<stdlib.h>
int main(){
	int *arr,i,n;
	printf("Enter the no. of students:\n");
	scanf("%d",&n);
	arr=(int*)malloc(n*sizeof(int));
/*	printf("Enter student marks:\n");
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	} */
	printf("Student marks:\n");
	for(i=0;i<n;i++){
		printf("%d",arr[i]);
	}
}
