#include<stdio.h>
int onehuafen(int *A,int low,int high)
{
	int pivot=A[low];
	while(low<high)
	{
		while(pivot<=A[high]&&low<high)
		high--;
		A[low]=A[high];
		while(pivot>=A[low]&&low<high)
		low++;
		A[high]=A[low];
	}
	A[low]=pivot;
	return low;
}//��������һ�λ��� 
void Qsort(int *A,int low,int high)
{
	if(low<high)
	{
		int mid=onehuafen(A,low,high);
		Qsort(A,low,mid-1);
		Qsort(A,mid+1,high);
	}
}//������������ 
int a[1000000];
int main()
{
	int i,j,n,m;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		scanf("%d",&m);
	    for(i=n;i<n+m;i++)
		  {
			scanf("%d",&a[i]);
		  }
		//�������������Ѻϲ�
		 
		Qsort(a,0,n+m-1);//�������� 
		
		printf("%d",a[(n+m-1)/2-1]) ;
		
	}
	return 0;
}
