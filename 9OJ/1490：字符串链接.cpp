#include<stdio.h>
#include<string.h>
void MyStrcat(char dstStr[],char srcStr[]){
    int len1,len2,i=0;
    len1=strlen(dstStr);
    len2=strlen(srcStr);
	for(len2;len2>=0;len2--)dstStr[len1++]=srcStr[i++];
}//×Ö·û´®Á´½Óº¯Êý 
char s1[2000],s2[1000];
int main(){
	while(scanf("%s%s",s1,s2)!=EOF){
		MyStrcat(s1,s2);
		printf("%s\n",s1);
	}
	return 0;
}
