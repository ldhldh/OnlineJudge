#include<stdio.h>
#include<string.h>
char str1[1050];
char str2[1050];
int a[1050];
int main(){
	while(scanf("%s %s",str1,str2)!=EOF)
	{ 
		int l1=strlen(str1);
		int l2=strlen(str2);
		int len=l1>l2?l1:l2;
		int i=l1-1,j=l2-1;
		int carry=0;//进位标识 
		int k=0;
		int x;
		for(;i>=0&&j>=0;i--,j--)
		{
			x=str1[i]-'0'+str2[j]-'0'+carry;
			carry=x/10;
			x%=10;
			a[k++]=x; 
		}
		while(i>=0)
		{
			x=str1[i--]-'0'+carry;
			carry=x/10;
			x%=10;
			a[k++]=x;
		}
		while(j>=0)
		{
			x=str1[j--]-'0'+carry;
			carry=x/10;
			x%=10;
			a[k++]=x;
		}
		if(carry!=0)
            printf("1");
		for(i=len-1;i>=0;i--)
		printf("%d",a[i]);
		printf("\n");
	}
	return 0;
}
