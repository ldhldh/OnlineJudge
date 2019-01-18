#include<stdio.h>
int a[6],b[6],c[4];
int main(){
	while(scanf("%d",&a)!=EOF){
	for(int i=1;i<6;i++)scanf("%d",&a[i]);
	for(int i=0;i<6;i++)scanf("%d",&b[i]);
	c[0]=a[0]*b[0]+a[1]*b[2]+a[2]*b[4];
	c[1]=a[0]*b[1]+a[1]*b[3]+a[2]*b[5];
	c[2]=a[3]*b[0]+a[4]*b[2]+a[5]*b[4];
	c[3]=a[3]*b[1]+a[4]*b[3]+a[5]*b[5];
	printf("%d %d \n%d %d \n",c[0],c[1],c[2],c[3]);
	}
	return 0;
 } 
