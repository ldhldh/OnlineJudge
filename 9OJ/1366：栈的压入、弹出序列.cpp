#include<stdio.h>
#include<stack>
using namespace std;
int a[100003];
int b[100003];
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		stack<int>S;
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		for(int i=0;i<n;i++){
			scanf("%d",&b[i]);
		}
		int i=0,j=0;
		/*while(i<n){
		    S.push(a[i++]);	
			while(!S.empty()&&S.top()==b[j]){
				S.pop();
				j++;
			}
		}*/
		int ok=1;
		while(j<n){
			if(i<n&&a[i]==b[j]){//i<nºÜÖØÒª 
				i++;
				j++;
			}
			else if(!S.empty()&&S.top()==b[j]){
			    S.pop();
				j++;	
			}
			else if(i<n){
			    S.push(a[i++]);	
			}
			else {
				ok=0;
				break;
			}
		}
		if(ok==1)printf("Yes\n");
		else printf("No\n");
	}
	return 0;
} 
