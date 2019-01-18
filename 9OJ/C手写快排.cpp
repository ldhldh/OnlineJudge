#include<stdio.h>
int partition(int *a,int left,int right)
{
    a[0] = a[left];  //����a[left]Ϊ����ֵ������a[0]������a[left]ֵ��[left,right]����һ��Ϊ��
    while(left<right)
    {
        while(left<right&&a[right]>=a[0]) right--;  //���ұ߿�ʼ�ҵ�������ֵa[0]С��ֵ���Ƶ����
        a[left]=a[right];
        while(left<right&&a[left]<=a[0]) left++;    //����߿�ʼ�ҵ�������ֵa[0]���ֵ���Ƶ��ұ�
        a[right]=a[left];
    }
    a[left] = a[0];  //����whileѭ�����left==right����ʱ�������Ѿ�һ��Ϊ���ˣ���a[left]��ֵ��ԭ
    return left;
}

void QuickSort(int *a,int left,int right)
{
    if(left<right)  //��������Ҫ����1
    {
        int mid = partition(a,left,right);  //����һ�λ��֣���a[left]��������Ϊ������������
        QuickSort(a,left,mid-1);   //����������н�һ������
        QuickSort(a,mid+1,right);  //����������н�һ������
    }
}

int main()
{
    int n;
    int a[10000];
    while(~scanf("%d",&n))
    {
        int i;
        for(i=1;i<=n;i++)
        {
            scanf("%d",a+i);
        }
        QuickSort(a,1,n);
        for(i=1;i<=n;i++)
        {
            printf("%d ",a[i]);
        }
        putchar(10);
    }
    return 0;
}
