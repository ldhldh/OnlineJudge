#include<stdio.h>
#include <string.h>
char str[100];
int main(){
  while(scanf("%s",str)!=EOF){
  	int n1,n2;
	int N=strlen(str);
	int R=(N+2)%3;
	int Q=(N+2)/3;
    if(R==0){
    	n1=n2=Q;
	}
	else{
		n1=Q;
		n2=N-2*Q+2;
	}
	int j=0;
	for(j;j<=n1-2;j++){
		printf("%c",str[j]);
		for(int k=n2-2;k>0;k--)putchar(' ');
		printf("%c\n",str[N-j-1]);
	}
	for(n2;n2>0;n2--){
		printf("%c",str[j]);
		j++;
	}
	printf("\n");
  }
  return 0;
 } 
