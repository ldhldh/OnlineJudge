//pre为前序， ord为中序， aft为后序。
#include<stdio.h>
#include<string.h>
//int i,c;
void aft(char p[], char o[], int l)
{
    if(l <= 0)
        return ;
    int i,c;
     c = p[0];
    for(i = 0; i < l; i++)
    {
        if(p[0] == o[i])
        break;
    }
    aft(p + 1, o, i);
    aft(p + i + 1, o + i + 1, l - (i + 1));
    printf("%c",c);
}
int main(void)
{
    char pre[10000], ord[10000];
    while(scanf("%s%s", pre, ord)!=EOF)
    {
        aft(pre, ord, strlen(pre));
        printf("\n");
    }
  
    return 0;
}
