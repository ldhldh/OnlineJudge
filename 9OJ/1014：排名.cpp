#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
struct E{
	char num[25];
	int g;
	bool operator < (const E &b)const{
	if(g!=b.g)return g>b.g;
	else{
		int tmp=strcmp(num,b.num);
		return tmp<0;
	}
	}
}student[1002];
/*bool cmp(E a,E b){
    if(a.g!=b.g)return a.g>b.g;
    else{
		int tmp=strcmp(a.num,b.num);
		return tmp<0;
	}
} */
int main(){
	int N,M,G,m,t; 
	int sore[12]={0};
	while(scanf("%d %d %d",&N,&M,&G)!=EOF){
		if(N==0)break;
		int count=0;
		for(int i=1;i<=M;i++)scanf("%d",&sore[i]);
		for(int i=0;i<N;i++){
			int grade=0;
			scanf("%s %d",&student[i].num,&m);
			for(int j=0;j<m;j++){
				scanf("%d",&t);
				grade+=sore[t];
			}
			student[i].g=grade;
			if(grade>=G)count++;
		}
		printf("%d\n",count);
		if(count>0)sort(student,student+N);
		for(int i=0;count>0;i++){
		    printf("%s %d\n",student[i].num,student[i].g );
			count--;
		}
	}
	return 0;
} 
