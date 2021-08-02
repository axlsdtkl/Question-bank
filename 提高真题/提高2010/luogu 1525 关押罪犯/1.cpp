#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define M 110000
#define N 41000
struct arr{int x,y,z;}a[M];
int n,m,fa1,fa2,x,y,i;
int fa[N];
int cmp(arr a,arr b){return a.z>b.z;}
int getfa(int x){return fa[x]==x?x:fa[x]=getfa(fa[x]);}
int main()
{
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++)scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
	sort(a+1,a+m+1,cmp);
	for(i=1;i<=n*2;i++)fa[i]=i;
	for(i=1;i<=m;i++)
	{
		x=a[i].x;y=a[i].y;
		if(getfa(x)==getfa(y))
		{
			printf("%d\n",a[i].z);
			return 0;
		}
		fa1=getfa(x);fa2=getfa(y+n);
		if(fa1!=fa2)fa[fa2]=fa1;
		fa1=getfa(x+n);fa2=getfa(y);
		if(fa1!=fa2)fa[fa2]=fa1;
	}
	printf("0\n");
	return 0;
}