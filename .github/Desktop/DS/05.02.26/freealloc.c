#include<stdlib.h>
int main(){
	int *arr,i,n;
	printf("Enter the no. of students:\n");
	scanf("%d",&n);
	arr=(int*)calloc(n,sizeof(int));
	printf("Enter student marks:\n");
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	} 
	printf("Student marks:\n");
	for(i=0;i<n;i++){
		printf("%d",arr[i]);
	}
	free(arr);
	printf("After free called:");
	for(i=0;i<n;i++){
		printf("%d\t",arr[i]);
	}
}
