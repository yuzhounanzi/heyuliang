#include<stdio.h>
void swap(int* arr,int a,int b){//交换函数 
	int t=arr[a];
	arr[a]=arr[b];
	arr[b]=t;
}

int partation(int* arr,int low,int high){//切分 
	int t=arr[low];
	int i=low+1;
	int j=high;
	while(1){
		while(i<=high){
			if(arr[i]>=t){
				break;
			}
			else{
				i++;
			}
		}
		while(j>=low){
			if(arr[j]<=t){
				break;
			}
			else{
				j--;
			}
		}
		if(i>=j){
			break;
		}
		else{
			swap(arr,i,j);
		}
	}
	swap(arr,low,j);
	return j;
}


void quicksort(int* arr,int low,int high){//在low到high上有序 
	if(low>=high){
		return;
	}
	int j=partation(arr,low,high);
	quicksort(arr,low,j-1);
	quicksort(arr,j+1,high);
}




int main()
{
	int arr[10];
	for(int i=0;i<10;i++){
		scanf("%d",&arr[i]);
	}
	quicksort(arr,0,9);
	for(int i=0;i<10;i++){
		printf("%d ",arr[i]);
	}
	return 0;
} 
