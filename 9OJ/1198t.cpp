#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char a[1012]={0};
char b[1012]={0};
char c[1012]={0};
int main(int argc, char *argv[])
{
    // freopen("in.txt","r",stdin);
    while(scanf("%s%s",a,b)!=EOF)
    {
        int len1=strlen(a),len2=strlen(b);
        int len=len1>len2?len1:len2;
        int carry=0;
        int i=len1-1,j=len2-1,k=len-1;
        for(;i>=0 && j>=0;i--,j--,k--)
        {
            int tmp=a[i]-'0'+b[j]-'0'+carry;
            carry=tmp/10;
            tmp%=10;
            c[k]=tmp;
        }
        while(j>=0)
        {
            int tmp=b[j--]-'0'+carry;
            carry=tmp/10;
            tmp=tmp%10;
            c[k--]=tmp;
        }
        while(i>=0)
        {
            int tmp=a[i--]-'0'+carry;
            carry=tmp/10;
            tmp=tmp%10;
            c[k--]=tmp;
        }
        if(carry!=0)
            printf("1");
        for(i=0;i<len;++i)
            printf("%d",c[i]);
        printf("\n");
    }
    return 0;
}
  
/**************************************************************
    Problem: 1198
    User: kirchhoff
    Language: C
    Result: Accepted
    Time:120 ms
    Memory:916 kb
****************************************************************/
