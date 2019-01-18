#include <stdio.h>
#define maxsize 110
char str[110];
char ans[110];
typedef struct stack{
    int data[maxsize];
    int top;
}stack;
stack s;
void init()
{
    s.top=-1;
}
int empty()
{
    if(s.top==-1)
        return 1;
    else return 0;
}
int full()
{
    if(s.top==maxsize-1)
        return 1;
    else return 0;
}
void push(int e)
{
    if(full())
        return;
    else
    {
        s.top++;
        s.data[s.top]=e;
    }
}
void pop()
{
    if(!empty())
    {
        s.top--;
    }
    else return;
}
  
int getTop()
{
    if(!empty())
    {
        return s.data[s.top];
    }
    else return -1;
}
  
int main()
{
    while(scanf("%s",str)!=EOF)
    {   
        int i;
        for(i=0;str[i]!=0;i++)
        {
            if(str[i]=='(')
            {
                push(i);
                ans[i]=' ';
            }
            else if(str[i]==')')
            {
                if(!empty())
                {
                    pop();
                    ans[i]=' ';
                }
                else
                {
                    ans[i]='?';
                }
            }
            else ans[i]=' ';
        }
        while(!empty())
        {
            ans[getTop()]='$';
            pop();
        }
        ans[i]=0;
        puts(str);
        puts(ans);
    }
    return 0;
}
 
/**************************************************************
    Problem: 1153
    User: gp2299
    Language: C
    Result: Accepted
    Time:0 ms
    Memory:916 kb
****************************************************************/
