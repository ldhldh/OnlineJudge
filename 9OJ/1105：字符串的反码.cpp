#include<stdio.h>
#include<string.h>
int main(){
	char s[80]={};
	while(gets(s)){
		if(s[0]=='!'&&strlen(s)==1){
		//printf("%d",strlen(s));
		//���ĺ�Ӣ�ĵ�!������ 
		break;
		}
		int N=strlen(s);
		for(int i=0;i<N;i++){
			if('A'<=s[i]){
				if(s[i]<='Z'){
					s[i]='Z'+'A'-s[i];
				}
				if('a'<=s[i]){
					if(s[i]<='z'){
					s[i]='z'+'a'-s[i];
				}
			}
			//if('a'<s[i]<'z')s[i]='z'+'a'-s[i];
			//if('A'<s[i]<'Z')s[i]='Z'+'A'-s[i];
			//������3����ͬʱ�ȴ�С �����Ҫ�ã���Ҫ&&���� 
		}
		
	}
	puts(s);
}
    return 0;
}
