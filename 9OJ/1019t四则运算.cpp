#include<stdio.h>
#include<string.h>
#include<ctype.h>
 
char s[300],sym[200];
int tops,topn;
double num[200];
 
int pri(char c)
{
    if(c=='#') return 1;
    else if(c=='+'||c=='-') return 2;
    else if(c=='*'||c=='/') return 3;
}
 
void cal(char c)
{
    double b=num[topn--];
    double a=num[topn--];
    double x;
    if(c=='+')  x=a+b;
    else if(c=='-')  x=a-b;
    else if(c=='*')  x=a*b;
    else if(c=='/')  x=a/b;
    num[++topn]=x;
}
 
int main()
{   
    int i,l;
    double x;
    gets(s);
    while(strcmp(s,"0")!=0)
    {
        tops=topn=-1;
        sym[++tops]='#';
        l=strlen(s);
        for(i=0;i<l;i++)
        {
            x=0;
            if(isdigit(s[i]))
            {
                while(isdigit(s[i]))
                    x=x*10+(double)(s[i++]-'0');
                num[++topn]=x;
            }
            else if(s[i]!=' ')
            {
                while(pri(s[i])<=pri(sym[tops]))
                    cal(sym[tops--]);
                sym[++tops]=s[i];
            }
        }
        while(tops>0)
            cal(sym[tops--]);
        printf("%.2lf\n",num[0]);
        gets(s);
    }
    return 0;
}
