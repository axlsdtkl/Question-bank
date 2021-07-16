#include<cstdio>
int x,i,j,ans;
int main(){
	scanf("%d",&x);
	for(i=1;i<=1000;i++)
		for(j=1;j<=i;j++){
			ans+=i;
			x--;
			if(x==0){
				printf("%d\n",ans);
				return 0;
			}
		}
	return 0;
}