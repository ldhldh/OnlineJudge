#include<stdio.h>
#include<malloc.h>
 
typedef struct node{
    int data;
    struct node *next;
}LinkList;
 
int main()
{
    int n,i;
    LinkList *head,*pre,*p,*newNode;
    while(scanf("%d",&n)!=EOF){
        head=(LinkList *)malloc(sizeof(LinkList));
        head->next=NULL;
        for(i=0;i<n;i++){
            newNode=(LinkList *)malloc(sizeof(LinkList));
            scanf("%d",&newNode->data);
            pre=head;
            p=head->next;
            while(p){
                if(newNode->data < p->data)
                    break;
                pre=p;
                p=p->next;
            }
            newNode->next=p;
            pre->next=newNode;
        }
        p=head->next;
        printf("%d",p->data);
        while(p->next){
            p=p->next;
            printf(" %d",p->data);
        }
        printf("\n");
    }
    return 0;
}
