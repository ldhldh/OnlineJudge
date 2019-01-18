#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
struct E{
	int num;
	char name[9];
	int g;
	bool operator < (const E &b)const{
	return num<b.num;
	}
}student[100001];
/*bool cmp1(E a,E b){
    return a.num<b.num;	
}*/
bool cmp2(E a,E b){
    int tmp1=strcmp(a.name,b.name);
    if(tmp1==0)
	return a.num<b.num;
	else return tmp1<0;
}
bool cmp3(E a,E b){
    int tmp2=a.g-b.g;
    if(tmp2==0)
	return a.num<b.num;
	else return tmp2<0;
}
int main(){
	int n,C,k=1;
	while(scanf("%d %d",&n,&C)!=EOF){
		if(n==0)break;
		for(int i=0;i<n;i++){
	        scanf("%d %s %d",&student[i].num,&student[i].name,&student[i].g);	
		}
		printf("Case %d:\n",k++);
		if(C==1)
			sort(student,student+n);	
		if(C==2)
			sort(student,student+n,cmp2);
		if(C==3)
			sort(student,student+n,cmp3);
		for(int i=0;i<n;i++)
			printf("%06d %s %d\n",student[i].num,student[i].name,student[i].g);					
	}
	return 0;
}
