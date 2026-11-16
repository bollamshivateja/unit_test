#include<stdio.h>
main(){
	int a[10],n,i,mid,low,high;
	printf("\nEnter the size of array:");
	scanf("%d",&n);
	printf("\nEnter elements:");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	mergesort(a,low,n-1);
	for(i=0;i<n;i++){
		printf("%d\t",a[i]);
	}
}
void mergesort(int a[],int low,int high){
	if(low<high){
		int mid=(low+high)/2;//calculate the mid
		mergesort(a,low,mid);
		mergesort(a,mid+1,high);
		merge(a,low,mid,high); //merge the sorted values
	}
}
void merge(int a[],int low,int mid,int high){
	int i,k,j;
	int n1=mid-low+1;
	int n2=high-mid;
	//create temporary arrays
	int lowa[n1],higha[n2];
	//copy data to temporary arrays
	for(i=0;i<n1;i++){
		lowa[i]=a[low+i];
	}for(j=0;j<n2;j++){
		higha[j]=a[mid+1+j];
	}i=0;
	j=0;
	k=low;
	while(i<n1&&j<n2){
		if(lowa[i]<=higha[i]){
			a[k]=lowa[i];
			i++;
		}else{
			a[k]=higha[j];
			j++;
		}k++;
	}//copy the remaining elements of lowa[],if any
	 while(i<n1){
	 	a[k] = lowa[i];
	 	i++;
	 	k++;
	 }
	  //copy the remaining elements of higha[],if any
	   while(j<n2){
	 	a[k] = higha[j];
	 	j++;
	 	k++;
	 }
}
