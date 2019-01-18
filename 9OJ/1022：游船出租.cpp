#include<stdio.h>
struct ship{
	int m;
	double time;
};
typedef struct ship shipnode;
shipnode a[101];
void inita(int n){
	a[n].m=0;
	a[n].time=0;
}
int main(){
	for(int i=0;i<=100;i++)inita(i);
	int x,z1,z2,N=0;
	double T;
	char y;
	while(true){
		scanf("%d %c %d:%d",&x,&y,&z1,&z2);
		if(x==0){
			if(N==0)printf("0 0\n");
			else {
				printf("%d %.0f\n",N,T/N);
			}
			for(int i=0;i<=100;i++)inita(i);
			T=0,N=0;
		}
        if(x==-1)break;
	    if(x>0&&x<101&&y=='S'&&a[x].m==0){
				a[x].m=1;
				a[x].time=z1*60+z2;
		}
		if(x>0&&x<101&&y=='E'&&a[x].m==1){
			    a[x].m=0;
			    T=T+z1*60+z2-a[x].time;
			    N++;
		}
	}
	return 0;
}
