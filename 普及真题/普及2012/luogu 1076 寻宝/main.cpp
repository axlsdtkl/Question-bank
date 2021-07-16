#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
#define mo 20123
int n,m,i,j,ans,x,cs;
int a[11000][110],b[11000][110];
int c[11000];
int main()
{
	//freopen("1.in","r",stdin);
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		for(j=0;j<m;j++)
		{
			scanf("%d%d",&a[i][j],&b[i][j]);
			if(a[i][j])c[i]++;
		}
	scanf("%d",&x);
	for(i=1;i<=n;i++)
	{
		ans=(ans+b[i][x])%mo;
		cs=b[i][x]%c[i];
		if(cs==0)
		{
			if(x==0)x=m-1;else x--;
			while(a[i][x]==0)
			{
				if(x==0)x=m-1;else x--;
			}
			continue;
		}
		for(;;)
		{
			if(a[i][x])cs--;
			if(cs==0)break;
			x=(x+1)%m;
		}
	}
	printf("%d\n",ans);
	return 0;
}