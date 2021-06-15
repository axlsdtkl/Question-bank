#include<bits/stdc++.h>
using namespace std;
int n,m,i,ans,ans1,x,y;
int main(){
	scanf("%d%d",&n,&m);
	if(n>m)swap(n,m);
	for(i=1;i<=n;i++)x+=i;
	for(i=1;i<=m;i++)y+=i;
	ans=x*y;
	for(i=1;i<=n;i++)ans1+=(n-i+1)*(m-i+1);
	printf("%d %d\n",ans1,ans-ans1);
	return 0;
}
