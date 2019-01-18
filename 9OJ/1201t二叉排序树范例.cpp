#include <stdio.h>
#include <string.h>
 
struct binaryTree{
    struct binaryTree *lchild;
    struct binaryTree *rchild;
    int c;
};
typedef struct binaryTree Node;
Node Tree[100];
int loc;
Node *creat(){
    Tree[loc].lchild = Tree[loc].rchild = NULL;
    return &Tree[loc++];
}
void preOrder(Node *T){
    printf("%d ", T -> c);
    if(T -> lchild != NULL){
        preOrder(T -> lchild);
    }
    if(T -> rchild != NULL){
        preOrder(T -> rchild);
    }
}
void midOrder(Node *T){
     
    if(T -> lchild != NULL){
        midOrder(T -> lchild);
    }
    printf("%d ", T -> c);
    if(T -> rchild != NULL){
        midOrder(T -> rchild);
    }
}
void postOrder(Node *T){
    if(T -> lchild != NULL){
        postOrder(T -> lchild);
    }
    if(T -> rchild != NULL){
        postOrder(T -> rchild);
    }
    printf("%d ", T -> c);
}
Node *Insert(Node *T, int x){
    if(T == NULL){
        T = creat();
        T -> c = x;
        return T;
    }else if(x < T -> c){
        T -> lchild = Insert(T -> lchild , x);
    }else if(x > T -> c){
        T -> rchild = Insert(T -> rchild, x);
    }
    return T;
}
int main()
{
    int n;
    while(scanf("%d", &n) != EOF){
        loc = 0;
        Node *T = NULL;
        for (int i = 0; i < n; ++i)
        {
            int x;
            scanf("%d", &x);
            T = Insert(T,x);
        }
        preOrder(T);
        printf("\n");
        midOrder(T);
        printf("\n");
        postOrder(T);
        printf("\n");
 
    }
    return 0;
}
