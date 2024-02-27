#include<stdio.h>
#include<stdlib.h>
void swap(int* arr,int l,int r)//�������� 
{
	int temp;
	temp=arr[r];
	arr[r]=arr[l];
	arr[l]=temp;
}
void heapInsert(int* arr,int index){//��indexλ�õ��������ߣ�����Ϊ����� 
	while(arr[index]>arr[(index-1)/2])//index���������ĸ���㣬���ϵ��� 
	{
		swap(arr,index,(index-1)/2);
		index=(index-1)/2;
	}
}


void heapify(int* arr,int index,int heapsize){//��index��������ߣ�����Ϊ����� 
	int largest; 
	while(index*2+1<heapsize)//indexû�к���ʱ����ѭ�� 
	{
		largest=index*2+2<heapsize&&arr[index*2+2]>arr[index*2+1]? index*2+2:index*2+1;
		//���Һ��Ӵ������Һ��Ӵ�������ʱ�����Һ����±긳��largest�����������±긳��largest
		largest=arr[largest]>arr[index]?largest:index;
		//�����Ӵ��ڸ�ʱ���������±긳��largest�����򽫸��±긳��largest
		if(largest==index)//������Ѿ���������õ���������ѭ�� 
		{
			break;	
		} 
		swap(arr,index,largest);//�������ӽ�㽻�� 
		index=largest;
	}
}




void heapsort(int* arr,int length){//������ 
	for(int i=0;i<length;i++)//��С��������Ҫ���������Ϊ����� 
	{
		heapInsert(arr,i);//��ÿ���������� 
	}
	int heapsize=length;//heapsize��ʾ��ǰ�ж��ٸ���Ϊ�ѽṹ
	swap(arr,0,--heapsize);//����һ���������һ�����������ѽṹ��ȥ�����һ���� 
	while(heapsize>0)
	{
		heapify(arr,0,heapsize);//ÿ��ѭ����0λ�õ��������ߣ�����Ϊ�ѽṹ
		swap(arr,0,--heapsize);//����һ���������һ�����������ѽṹ��ȥ�����һ����  
	}
} 




void merge(int* arr,int l,int mid,int r){
	int* tarr=(int*)malloc(sizeof(int)*(r-l+1));//����һ����ʱ�ռ�
	int temp=0;//tempָ��ָ����ʱ�ռ�
	int i,j;//iָ����jָ����
	i=l;
	j=mid+1;
	while(i<=mid&&j<=r)//��ֹԽ�� 
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
		arr[l+temp]=tarr[temp];//����ʱ���鸳��ԭ���� 
	}
	free(tarr); 
}


void processmerge(int* arr,int left,int right){//�鲢����,��left��right������ 
	if(left==right)
	{
		return;
	}
	int mid=(left+right)/2;
	processmerge(arr,left,mid);//��߷���
	processmerge(arr,mid+1,right);//�ұ߷���
	merge(arr,left,mid,right);//�鲢 
}




void insert(int* arr,int length){//�������� 
	int i,j;
	for(i=1;i<length;i++) 
	{
		for(j=i;j>0;j--)//���ĸ���Χ�����򣬴Ӻ���ǰ 
		{
			if(arr[j]<arr[j-1])
			{
				swap(arr,j,j-1);
			}
		}
	}
}


void choose(int* arr,int length){//ѡ������ 
	int minindex;
	int i,j;
	for(i=0;i<length;i++)
	{
		minindex=i;//minindex��¼��ǰС��ֵ���±�
		for(j=i+1;j<length;j++)//ѡ����С�� 
		{
			if(arr[j]<arr[minindex])
			{
				minindex=j;	
			}	
		}
		//��arr[minindex]��max[i]���� 
		swap(arr,i,minindex);
	}
}

void bubble(int* arr,int length){//ð������ 
	int i,j;
	for(i=length-1;i>0;i--)//���ĸ���Χ��ð�� 
	{
		for(j=0;j<i;j++)//�����ð����ȥ 
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
