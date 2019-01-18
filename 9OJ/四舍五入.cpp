#include<stdio.h>
int main()
{
	double T;
	int N;
	scanf("%lf %d",&T,&N); //double对应%lf 
	int a=(int)(T/N+0.5);
		printf("%d\n",a);//第一种四舍五入，T/N得是小数才有效，也就是T是double 
	    printf("%.0f\n",T/N);//第一种四舍五入，通过输出格式调整完成，T必须是double 
		return 0;
}
