#include<stdio.h>
#include <string.h>
#include<stdlib.h>
  
typedef struct tnode{
    char data;
    struct tnode *left;
    struct tnode *right;
}tnode;
  
char result[100],count = 0;
 
char pre[100],in[100];
 
tnode *t_post(char *pre,char *in,int len){
    if(len<=0) {
        tnode *t = NULL;
        return t;
    }
    int i;
  
    tnode *t =(tnode *)malloc(sizeof(tnode));
    for(i = 0;i<len;i++){
        if(*(in+i) == *pre){
            t->data = *pre;
            break;
        }
    }
    t->left = t_post(pre+1,in,i);
    t->right = t_post(pre+i+1,in+i+1,len-i-1);
    return t;
}
  
void post_order(tnode *t){
    if(t->left!=NULL){
        post_order(t->left);
    }
    if(t->right!=NULL)       
        post_order(t->right);
    printf("%c",t->data);
}
int main(){
  
    int len;
     while(scanf("%s",pre)!=EOF)
    {
        scanf("%s",in);
 
        tnode *T =(tnode *)malloc(sizeof(tnode));
 
        len = strlen(pre); //虽然gets送去五个值但是最后一个结束0，strlen并不计算在内
        T = t_post(pre,in,len);
        len++;
  
        post_order(T);
        printf("\n");
    }
    return 0;
}
