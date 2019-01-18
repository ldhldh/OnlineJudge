#include<stdio.h>
#include<stdlib.h>
typedef struct node node;
struct node
{
    int data;
    node *left;
    node *right;
};
node* creat(int *s,int n)
{
    int i,j; 
    node **b,*q;
    b=(node**)malloc(n*sizeof(node));
    for(i=0;i<n;i++)
    {
      b[i]=(node*)malloc(sizeof(node));
      b[i]->data=s[i];
      b[i]->left=b[i]->right=NULL;    
     } 
     for(i=1;i<n;i++)
     {
        int k1=-1,k2;
        for(j=0;j<n;j++)//寻找第一个和第二个 
         {
            if(b[j]!=NULL&&k1==-1)
              {k1=j;continue;}
             if(b[j]!=NULL)
                 {k2=j;break;}
         }
         for(j=k2;j<n;j++)
          {
           if(b[j]!=NULL)
            {
                  
                if(b[k1]->data>b[j]->data)
                    {k2=k1;k1=j;}
                else if(b[k2]->data>b[j]->data)
                      k2=j;
            }   
          } 
          q=(node*)malloc(sizeof(node));
          q->data=b[k1]->data+b[k2]->data;
          q->left=b[k1];
          q->right=b[k2];
          b[k1]=q;   //update operating
          b[k2]=NULL;
     }
     free(b);
     return q;
}
int weight(node* FBT,int lenght)
{
    if(FBT==NULL)
      return 0;
    if(FBT->left==NULL&&FBT->right==NULL)
      return FBT->data*lenght;
     else return weight(FBT->left,lenght+1)+weight(FBT->right,lenght+1);
}
int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        int s[1000];
        node* fbt;
        for(int i=0;i<n;i++)
          scanf("%d",&s[i]);
        fbt=creat(s,n);
        printf("%d\n",weight(fbt,0));
    }
  return 0; 
 } 
