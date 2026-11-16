#include<stdlib.h>
int main(){
	int *arr,i,n;
	printf("Enter the no. of students:\n");
	scanf("%d",&n);
	arr=(int*)malloc(n*sizeof(int));
	printf("Enter student marks:\n");
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	} 
	arr=(int*)realloc(arr,5);
	printf("Student marks:\n");
	for(i=0;i<n;i++){
		printf("%d\t",arr[i]);
	}
}

