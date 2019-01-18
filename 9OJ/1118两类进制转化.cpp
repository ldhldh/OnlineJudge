#include<stdio.h>
#include<string.h>
int main(){
	int a,b;
	char str[50];
	while(scanf("%d %s %d",&a,str,&b)!=EOF)
	{
		int length=strlen(str);
		int sum=0,c=1;
		for(int i=length-1;i>=0;i--)
		{
			int x;
			if('0'<=str[i]&&str[i]<='9')
			{
				x=str[i]-'0';
			}
			else if('a'<=str[i]&&str[i]<='f')
			{
				x=str[i]-'a'+10;
			}
			else if('A'<=str[i]&&str[i]<='F')
			{
				x=str[i]-'A'+10;
			}
			sum+=c*x;
			c*=a;
		}//把a进制转化成10进制 
		char ans[50],size=0;
		do{
			int x=sum%b;
			ans[size++]=(x<10) ? x+'0':x-10+'A';
			sum/=b;
		}while(sum!=0);
		for(int i=size-1;i>=0;i--)
		printf("%c",ans[i]);
		printf("\n");
	}//10进制转化成b进制并输出 
	return 0;
} 
