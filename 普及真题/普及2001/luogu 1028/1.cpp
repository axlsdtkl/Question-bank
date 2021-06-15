#include<bits/stdc++.h>
using namespace std;
int n,ans,f[2100];
int dfs(int x){
	if(f[x]>0)return f[x];
	f[x]=1;
	for(int i=1;i<=x/2;i++)f[x]+=dfs(i);
	return f[x];
}
int main(){
	scanf("%d",&n);
	ans=dfs(n);
	printf("%d\n",ans);
	return 0;
}
