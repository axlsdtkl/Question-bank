#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
#define M 610000
#define N 310000
struct edge{int n,o,l;}ee[M],e[M];
struct arr{int x,y,z,l;}a[310000];
int n,m,x,y,z,w,w1,temp,sum,cnt,max1,max2,i,j,l,r,mid,ww;
int last[N],lastt[N],de[N],f[N][21],ff[N][21],flag[N],mark[N];
int two[30];
void add1(int x,int y,int z)
{
	ww++;ee[ww].n=lastt[x];lastt[x]=ww;ee[ww].o=y;ee[ww].l=z;
}
void add(int x,int y,int z)
{
	w++;e[w].n=last[x];last[x]=w;e[w].o=y;e[w].l=z;
}
void dfs(int father,int now,int deep,int lo)
{
	int w1,y;
	de[now]=deep;
	f[now][0]=father;ff[now][0]=lo;
	flag[now]=1;
	for(w1=lastt[now];w1;w1=ee[w1].n)
	{
		y=ee[w1].o;
		if(flag[y]==0)dfs(now,y,deep+1,ee[w1].l),add(now,y,ee[w1].l);
	}
}
int lca(int x,int y)
{
	int cha,i;
	if(x==y)return x;
	if(de[x]<de[y])temp=x,x=y,y=temp;
	cha=de[x]-de[y];
	if(cha)
	{
		for(i=18;i>=0;i--)
		if(two[i]<=cha)
		{
			cha-=two[i];
			sum+=ff[x][i];
			x=f[x][i];
		}
	}
	if(x!=y)
	{
		for(i=18;i>=0;i--)
		{
			if(f[x][i]!=f[y][i])
			{
				sum+=ff[x][i];sum+=ff[y][i];
				x=f[x][i];y=f[y][i];
			}
		}
		sum+=ff[x][0];sum+=ff[y][0];
		x=f[x][0];y=f[y][0];
	}
	return x;
}
void dfs1(int x)
{
	int w1,y;
	for(w1=last[x];w1;w1=e[w1].n)
	{
		y=e[w1].o;
		dfs1(y);
		mark[x]+=mark[y];
	}
	if(mark[x]==cnt)max2=max(max2,ff[x][0]);
}
int work(int x)
{
	int i;
	for(i=1;i<=n;i++)mark[i]=0;
	cnt=0;max1=0;
	for(i=1;i<=m;i++)
	if(a[i].l>x)
	{
		cnt++;max1=max(max1,a[i].l);
		mark[a[i].x]++;mark[a[i].y]++;
		mark[a[i].z]-=2;
	}
	max2=-1;
	dfs1(1);
	if(max2>=max1-x)return 1;
	return 0;
}
int read()
{
	int x=0;
	char ch=getchar();
	while(ch>'9'||ch<'0')ch=getchar();
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return x;
}
int main()
{
	//freopen("1.in","r",stdin);
	scanf("%d%d",&n,&m);
	for(i=1;i<n;i++)x=read(),y=read(),z=read(),add1(x,y,z),add1(y,x,z),r+=z;
	dfs(0,1,1,0);
	for(i=1;i<=18;i++)
		for(j=1;j<=n;j++)
		f[j][i]=f[f[j][i-1]][i-1],ff[j][i]=ff[j][i-1]+ff[f[j][i-1]][i-1];
	two[0]=1;
	for(i=1;i<=18;i++)two[i]=two[i-1]<<1;
	for(i=1;i<=m;i++)
	{
		a[i].x=read();a[i].y=read();
		x=a[i].x;y=a[i].y;
		sum=0;
		a[i].z=lca(x,y);
		a[i].l=sum;
	}
	l=-1;r++;
	while(l+1<r)
	{
		mid=(l+r)/2;
		if(work(mid))r=mid;else l=mid;
	}
	printf("%d\n",r);
	return 0;
}