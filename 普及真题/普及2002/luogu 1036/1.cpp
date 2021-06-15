#include<bits/stdc++.h>
using namespace std;
int n,m,ans,a[30];
int pd(int x){
	for(int i=2;i<=sqrt(x);i++)
		if(x%i==0)return 0;
	return 1;
}
void dfs(int now,int cnt,int sum){
	if(cnt>m)return;
	if(cnt==m){
		if(pd(sum))ans++;
		return;
	}
	if(now>n)return;
	dfs(now+1,cnt,sum);
	dfs(now+1,cnt+1,sum+a[now]);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	dfs(1,0,0);
	printf("%d\n",ans);
	return 0;
}
