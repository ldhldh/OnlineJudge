#include<stdio.h>  
#include<stdlib.h>  
#include<math.h>  
int P,T,G1,G2,G3,GJ;  
int my_max(int x,int y)  
{  
    return x>y?x:y;  
}  
int main(int argc, char *argv[])  
{  
    while(scanf("%d %d %d %d %d %d",&P,&T,&G1,&G2,&G3,&GJ)!=EOF)  
    {  
        if(abs(G1-G2)<=T)  
            printf("%.1lf\n",(double)(G1+G2)/2.0);  
        else if(abs(G1-G3)<=T&&abs(G2-G3)<=T)  
            printf("%.1lf\n",my_max(my_max(G1,G2), G3));  
        else if(abs(G1-G3)>T&&abs(G2-G3)>T)  
            printf("%.1lf\n",(double)GJ);  
        else if(abs(G1-G3)<=T&&abs(G2-G3)>T)  
            printf("%.1lf\n",((double)(G3+G1))/2.0);  
        else if(abs(G2-G3)<=T&&abs(G1-G3)>T)  
            printf("%.1lf\n",((double)(G3+G2))/2.0);  
    }  
    return 0;  
}  
   
