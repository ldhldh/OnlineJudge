#include<stdio.h>
#include<string.h>
int main(){
	char s[80]={};
	while(gets(s)){
		if(s[0]=='!'&&strlen(s)==1){
		//printf("%d",strlen(s));
		//中文和英文的!有区别 
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
			//不可以3个数同时比大小 ，如果要用，需要&&连接 
		}
		
	}
	puts(s);
}
    return 0;
}
