//ac.jobdu.com/problem.php?pid=1096
#include<stdio.h>
#define run(x) x%100!=0&&x%4==0||x%400==0?1:0

//      int run(int x){
//	        int i;
//	        i=x%100!=0&&x%4==0||x%400==0?1:0;
//	        return i;
//          } 

int dayofmonth[13][2]=
{  
    0,0,  
    31,31,  
    28,29,  
    31,31,  
    30,30,  
    31,31,  
    30,30,  
    31,31,  
    31,31,  
    30,30,  
    31,31,  
    30,30,  
    31,31  
};
struct date{
	
	int year;
	int month;
	int day;
	void nextday()
	{
		day++;
		if(day>dayofmonth[month][run(year)])
		{
			day=1;
			month++;
			if(month>12)
			{
				month=1;
				year++;
			}
		}
	}
};
int count[5001][13][32];
int abs(int x){
	return x < 0 ? -x:x;
}
int main()
{
	 
	date firstday;
	firstday.year=0;
	firstday.month=1;
	firstday.day=1;
	int i=0;
	while(firstday.year<=5001)
	{
		count[firstday.year][firstday.month][firstday.day]=i;
		firstday.nextday();
		i++;
	}
	int y1,m1,d1,y2,m2,d2;
	while(scanf("%4d%2d%2d",&y1,&m1,&d1)!=EOF)
	{
		scanf("%4d%2d%2d",&y2,&m2,&d2);
		printf("%d\n",abs(count[y1][m1][d1]-count[y2][m2][d2])+1);
	}
	return 0;
}//问题2：为什么选择C++提交是accept，用C就编译失败？？？？？？？？？？？ 
