#include<stdio.h>
int main()
{
	double T;
	int N;
	scanf("%lf %d",&T,&N); //double��Ӧ%lf 
	int a=(int)(T/N+0.5);
		printf("%d\n",a);//��һ���������룬T/N����С������Ч��Ҳ����T��double 
	    printf("%.0f\n",T/N);//��һ���������룬ͨ�������ʽ������ɣ�T������double 
		return 0;
}
