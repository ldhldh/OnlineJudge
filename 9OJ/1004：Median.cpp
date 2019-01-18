#include<stdio.h>
int main(){
	long int N1,N2;
	while(scanf("%d",&N1)!=EOF){
		long int a[N1];
		for(long int i=0;i<N1;i++){
			scanf("%d",&a[i]);
		}
		if(scanf("%d",&N2)!=EOF){
			long int b[N1+N2];
			long int i=0,j=0,k=0,m;
			for(;j<N2;j++){
				scanf("%d",&m);
				while(a[i]<=m&&i<N1)
				{
					b[k++]=a[i++];
				}
				b[k++]=m;
			}
			while(k<N1+N2)
			{
				b[k++]=a[i++];
			}
			if((N1+N2)%2==0){
			printf("%d",b[(N1+N2)/2-1]);
		}
		else{
			printf("%d",b[(N1+N2)/2]);
		}
		}
	}
	return 0;
}
