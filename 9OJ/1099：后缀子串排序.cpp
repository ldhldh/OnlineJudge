#include<stdio.h>
#include<string.h>
int main(){
	char s[100],mmp[100]={};
	while(scanf("%s",s)!=EOF){
		int N=strlen(s);
		char str[N][100];
		for(int i=0;i<N;i++){
			int j=i;
			int n;
			for(int k=0;s[j]!=0;j++){
				str[i][k++]=s[j];
				n=k;
			}
			str[i][n]=0;
		}//得出所有子串 
		for(int i=0;i<N-1;i++)
		{
			for(int j=0;j<N-i-1;j++)
			{
				if(strcmp(str[j],str[j+1])>0)
				{
					strcpy(mmp,str[j]);
					strcpy(str[j],str[j+1]);
					strcpy(str[j+1],mmp);
				}
			}
		}//冒泡排序*/
		strcpy(mmp,s);
		for(int i=0;i<N;i++)printf("%s\n",str[i]); 
		printf("%s",mmp);
	}
	return 0;
}

