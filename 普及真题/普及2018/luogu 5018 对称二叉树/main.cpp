#include<bits/stdc++.h>
using namespace std;
#define N 1100000
struct arr{int left,right;}a[N];
int sum[N],b[N],flag[N],c[N];
int n,i,x,y,yes,ans,root;
void dfs1(int x,int y)
{
	if(x==-1&&y==-1)return;
	if(x==-1||y==-1){yes=0;return;}
	if(b[x]!=b[y]){yes=0;return;}
	dfs1(a[x].left,a[y].right);
	if(yes==0)return;
	dfs1(a[x].right,a[y].left);
	if(yes==0)return;
}
void work(int now)
{
	dfs1(a[now].left,a[now].right);
}
void dfs(int now)
{
	yes=1;
	work(now);
	if(yes)c[now]=1;
	sum[now]=1;
	if(a[now].left!=-1)dfs(a[now].left),sum[now]+=sum[a[now].left];
	if(a[now].right!=-1)dfs(a[now].right),sum[now]+=sum[a[now].right];
}
int main()
{
	//freopen("1.in","r",stdin);
	scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%d",&b[i]);
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&x,&y);
		if(x!=-1)flag[x]=1;
		if(y!=-1)flag[y]=1;
		a[i].left=x;a[i].right=y;
	}
	for(i=1;i<=n;i++)if(flag[i]==0)root=i;
	dfs(root);
	for(i=1;i<=n;i++)if(c[i])if(sum[i]>ans)ans=sum[i];
	printf("%d\n",ans);
	return 0;
}