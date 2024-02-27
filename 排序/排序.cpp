#include<stdio.h>
#include<stdlib.h>
void swap(int* arr,int l,int r)//交换函数 
{
	int temp;
	temp=arr[r];
	arr[r]=arr[l];
	arr[l]=temp;
}
void heapInsert(int* arr,int index){//把index位置的数向上走，调整为大根堆 
	while(arr[index]>arr[(index-1)/2])//index结点大于他的父结点，向上调整 
	{
		swap(arr,index,(index-1)/2);
		index=(index-1)/2;
	}
}


void heapify(int* arr,int index,int heapsize){//将index结点向下走，调整为大根堆 
	int largest; 
	while(index*2+1<heapsize)//index没有孩子时结束循环 
	{
		largest=index*2+2<heapsize&&arr[index*2+2]>arr[index*2+1]? index*2+2:index*2+1;
		//当右孩子存在且右孩子大于左孩子时，将右孩子下标赋给largest；否则将左孩子下标赋给largest
		largest=arr[largest]>arr[index]?largest:index;
		//当孩子大于父时，将孩子下标赋给largest，否则将父下标赋给largest
		if(largest==index)//父结点已经是最大，则不用调整，跳出循环 
		{
			break;	
		} 
		swap(arr,index,largest);//父结点和子结点交换 
		index=largest;
	}
}




void heapsort(int* arr,int length){//堆排序 
	for(int i=0;i<length;i++)//从小到大排序，要将数组调整为大根堆 
	{
		heapInsert(arr,i);//把每个数向上走 
	}
	int heapsize=length;//heapsize表示当前有多少个数为堆结构
	swap(arr,0,--heapsize);//将第一个数和最后一个数交换，堆结构中去掉最后一个数 
	while(heapsize>0)
	{
		heapify(arr,0,heapsize);//每次循环将0位置的数向下走，调整为堆结构
		swap(arr,0,--heapsize);//将第一个数和最后一个数交换，堆结构中去掉最后一个数  
	}
} 




void merge(int* arr,int l,int mid,int r){
	int* tarr=(int*)malloc(sizeof(int)*(r-l+1));//开辟一块临时空间
	int temp=0;//temp指针指向临时空间
	int i,j;//i指向左，j指向右
	i=l;
	j=mid+1;
	while(i<=mid&&j<=r)//防止越界 
	{
		tarr[temp++]=arr[i]<arr[j] ? arr[i++]:arr[j++];
	} 
	while(i<=mid)
	{
		tarr[temp++]=arr[i++];
	}
	while(j<=r)
	{
		tarr[temp++]=arr[j++];
	} 
	for(temp=0;temp<r-l+1;temp++)
	{
		arr[l+temp]=tarr[temp];//将临时数组赋给原数组 
	}
	free(tarr); 
}


void processmerge(int* arr,int left,int right){//归并排序,在left到right上有序 
	if(left==right)
	{
		return;
	}
	int mid=(left+right)/2;
	processmerge(arr,left,mid);//左边分治
	processmerge(arr,mid+1,right);//右边分治
	merge(arr,left,mid,right);//归并 
}




void insert(int* arr,int length){//插入排序 
	int i,j;
	for(i=1;i<length;i++) 
	{
		for(j=i;j>0;j--)//在哪个范围上有序，从后往前 
		{
			if(arr[j]<arr[j-1])
			{
				swap(arr,j,j-1);
			}
		}
	}
}


void choose(int* arr,int length){//选择排序 
	int minindex;
	int i,j;
	for(i=0;i<length;i++)
	{
		minindex=i;//minindex记录当前小的值的下标
		for(j=i+1;j<length;j++)//选出最小的 
		{
			if(arr[j]<arr[minindex])
			{
				minindex=j;	
			}	
		}
		//将arr[minindex]和max[i]交换 
		swap(arr,i,minindex);
	}
}

void bubble(int* arr,int length){//冒泡排序 
	int i,j;
	for(i=length-1;i>0;i--)//在哪个范围上冒泡 
	{
		for(j=0;j<i;j++)//将大的冒泡上去 
		{
			if(arr[j]>arr[j+1])
			{
				swap(arr,j,j+1);
			}
		}
	}
}




int main()
{
	
	int arr[10];
	int i;
	for(i=0;i<10;i++)
	{
		scanf("%d",&arr[i]);
	}
//	insert(arr,10);
//	choose(arr,10);
//	bubble(arr,10);
	heapsort(arr,10);
//	processmerge(arr,0,9);
	for(i=0;i<10;i++)
	{
		printf("%d ",arr[i]);
	}
	return 0;
}
