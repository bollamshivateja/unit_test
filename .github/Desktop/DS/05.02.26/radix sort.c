#include<stdio.h>
int main(){
	int n;
	printf("\nENter the size of array:\n");
	scanf("%d",&n);
	printf("\nEnter the values :\n");
	int a[10],i;
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	printf("\nPRINTING THE ELEMENTS :\n");
	printarray(a,n);
	radixsort(a,n);
	printf("After applying Radix Sort,tha array elements ara :\n");
	printarray(a,n);
	
}

int getmax(int a[],int n){
	int i,max=0;
		for(i=0;i<n;i++){
		if(max<a[i]){
			max=a[i];
		}
	}
	return max;
	
}
void countingsort(int a[],int n,int place){
	int output[n+1],i;
	int count[10]={0};
	//Calculate count of elements
	for(i=0;i<n;i++){
		count[(a[i]/place)%10]++;
	}	for (i=1;i<10;i++){
			count[i]=count[i]+count[i-1];
			//place the elements in sorted order 
			}for(i=n-1;i>=0;i--){
				int z=count[(a[i]/place)%10]-1;
				output[z]=a[i];
				count[(a[i]/place%10)]--;
			}for(i=0;i<n;i++){
				a[i]=output[i];
			}
			
}

void radixsort(int a[],int n){
	//get maximum element from array 
	int max=getmax(a,n);int place;
	//Apply counting sort to sort elements based on place value 
	for(place =1;max/place>0;place*=10){
	countingsort(a,n,place);
}
}
void printarray(int a[],int n){
	int i;
	for(i=0;i<n;++i){
		printf("%d\t",a[i]);
	}
	printf("\n");
}
