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
int a[1000];
int main()
{
	int i,j,n;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}//�õ�����
		
		int z;
		Qsort(a,0,n-1);//��������ʹҶ�Ӽ������� 
        /*for(i=1;i<n;i++)//����Ȩֵ��С��ǰ 
        {
            for(j=0;j<n-i;j++)
            {
                if(a[j]>a[j+1])
                {
                    z=a[j];
                    a[j]=a[j+1];
                    a[j+1]=z;
                }
            }
        }*/		
		
		int sum=0;
		for(i=0;i<n-1;i++)
		{
			sum+=a[i]+a[i+1];
			a[i+1]=a[i]+a[i+1];
			for(j=i+1;j<n-1;j++)
			{
				if(a[j]>a[j+1])
				{
	                z=a[j+1];
	                a[j+1]=a[j];
					a[j]=z;
				}
				else break;
			}//ʹ�¼����ٴ����� 
			
		}//�ۼӵ�sum��Ϊ���������Ĵ�Ȩ·������ 
		printf("%d\n",sum); 
	}
	
	return 0;
 } 
