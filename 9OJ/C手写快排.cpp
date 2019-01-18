#include<stdio.h>
int partition(int *a,int left,int right)
{
    a[0] = a[left];  //设置a[left]为主键值，存于a[0]，即以a[left]值将[left,right]区间一分为二
    while(left<right)
    {
        while(left<right&&a[right]>=a[0]) right--;  //从右边开始找到比主键值a[0]小的值，移到左边
        a[left]=a[right];
        while(left<right&&a[left]<=a[0]) left++;    //从左边开始找到比主键值a[0]大的值，移到右边
        a[right]=a[left];
    }
    a[left] = a[0];  //跳出while循环后的left==right，此时，区间已经一分为二了，将a[left]的值还原
    return left;
}

void QuickSort(int *a,int left,int right)
{
    if(left<right)  //快拍区间要大于1
    {
        int mid = partition(a,left,right);  //进行一次划分，以a[left]划分区间为左右两个区间
        QuickSort(a,left,mid-1);   //对左区间进行进一步划分
        QuickSort(a,mid+1,right);  //对左区间进行进一步划分
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
