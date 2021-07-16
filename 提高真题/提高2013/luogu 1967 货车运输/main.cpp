#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
struct arr{
	int x,y,z;
}a[51000];
struct edge{int n,o,l;}e[21000];
int ans,w,n,m,i,x,y,z,fa1,fa2,j,test,temp,cha,q;
int last[11000],de[11000],fa[11000],flag[11000];
int two[20];
int f[11000][20],bq[11000][20];
void add(int x,int y,int z)
{
	w++;
	e[w].n=last[x];
	last[x]=w;
	e[w].o=y;
	e[w].l=z;
}
int cmp1(arr a,arr b)
{	
	return a.z>b.z;
}
int getfa(int x){
	if(fa[x]==x)
	return x;
	else 
	return fa[x]=getfa(fa[x]);
}
int dfs(int fat,int now,int deep,int bb)
{
	int ww,y;
	f[now][0]=fat;
	de[now]=deep;
	bq[now][0]=bb;
	flag[now]=1;
	for(ww=last[now];ww;ww=e[ww].n)
	{
		y=e[ww].o;
		if(flag[y]==0)
		{
			dfs(now,y,deep+1,e[ww].l);
		}
	}
}
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++)
	scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
	sort(a+1,a+m+1,cmp1);
	for(i=1;i<=n;i++)
	fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		x=a[i].x;
		y=a[i].y;
		z=a[i].z;
		fa1=getfa(x);
		fa2=getfa(y);
		if(fa1!=fa2)
		{
			fa[fa1]=fa2;
			add(x,y,z);
			add(y,x,z);
		}
	}
	for(i=1;i<=n;i++)
		if(flag[i]==0)
		dfs(0,i,1,0);
	for(i=1;i<=15;i++)
		for(j=1;j<=n;j++)
		{
			f[j][i]=f[f[j][i-1]][i-1];
			bq[j][i]=min(bq[j][i-1],bq[f[j][i-1]][i-1]);
		}
	scanf("%d",&q);
	two[0]=1;
	for(int i=1;i<=15;i++)
	{
		two[i]=two[i-1]*2;
	}
	for(int i=q;i>0;i--)
	{
		
		scanf("%d%d",&x,&y);
		fa1=getfa(x);
		fa2=getfa(y);
		if(fa1!=fa2)
		{
			printf("-1\n");
			continue;
		}
		if(de[x]<de[y])
		{
			temp=x;
			x=y;
			y=temp;
		}
		cha=de[x]-de[y];
		ans=1000000000;
		for(int i=15;i>=0;i--)
		{
			if(cha>=two[i])
			{
				ans=min(ans,bq[x][i]);
				x=f[x][i];
				cha-=two[i];
			}
		}
		if(x!=y)
		{
			for(int i=15;i>=0;i--)
			{
				if(f[x][i]!=f[y][i])
				{
					ans=min(ans,bq[x][i]);
					ans=min(ans,bq[y][i]);
					x=f[x][i];
					y=f[y][i];
				}
			}
			ans=min(ans,bq[x][0]);
			ans=min(ans,bq[y][0]);
			x=f[x][0];
			y=f[y][0];
		}
		printf("%d\n",ans);
	}

	return 0;

}