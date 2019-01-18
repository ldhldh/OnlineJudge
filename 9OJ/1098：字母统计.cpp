#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std; 
char s[10000]={0};
struct Word{
	int l;
	int num;
}word[26];
int main(){
	while(cin>>s){
		for(int i=0;i<26;i++){
	        word[i].l=65+i; 
	        word[i].num=0;
        }
		int len=strlen(s);
		for(int i=0;i<len;i++){
			int k=s[i]-65;
			if(k>=0&&k<=25)word[k].num++;
		}
		for(int i=0;i<26;i++){
			printf("%c:%d\n",word[i].l,word[i].num);
		}
	}
	return 0;
}
