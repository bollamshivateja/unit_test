#include<stdio.h>
int main(){
	int n,i,j,tem;
	printf("Enter the n value:");
	scanf("%d",&n);
	int prices[n];
	for(i=0;i<n;i++){
		scanf("%d",&prices[i]);
	}
	for(i=0;i<n-1;i++){
	    for(j=0;j<n-i-1;j++){
	    	if(prices[j]>prices[j+1]){
	    		tem=prices[j];
	    		prices[j]=prices[j+1];
	    		prices[j+1]=tem;
			}
		}
		for(i=0;i<n;i++){
			printf("\n%d",prices[i]);
		}
	}
}

