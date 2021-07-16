#include<cstdio>
#include<algorithm>
using namespace std;
#define LL long long
struct arr{LL x,id;}d[110000];
LL a[110000],b[110000],c[110000],f[110000];
LL n,i,ans;
int cmp1(arr a,arr b){return a.x<b.x;}
void px(LL l,LL r)
{
	LL js1,js2,mid,l1,l2,i;
	if(l==r)return;
	mid=(l+r)/2;
	px(l,mid);px(mid+1,r);
	js1=0;js2=0;l1=1;l2=1;
	for(i=l;i<=mid;i++)b[++js1]=a[i];
	for(i=mid+1;i<=r;i++)c[++js2]=a[i];
	b[js1+1]=2147483647;
	c[js2+1]=2147483647;
	for(i=1;i<=js1+js2;i++)
	{
		if(b[l1]<=c[l2])a[l+i-1]=b[l1],l1++;
		else ans=(ans+js1-l1+1)%99999997 ,a[l+i-1]=c[l2],l2++;
	}
}	
int main()
{
	scanf("%lld",&n);
	for(i=1;i<=n;i++)scanf("%lld",&d[i].x),d[i].id=i;
	sort(d+1,d+n+1,cmp1);
	for(i=1;i<=n;i++)f[i]=d[i].id;
	for(i=1;i<=n;i++)scanf("%lld",&d[i].x),d[i].id=i;
	sort(d+1,d+n+1,cmp1);
	for(i=1;i<=n;i++)a[d[i].id]=f[i];
	px(1,n);
	printf("%lld\n",ans);
	return 0;
}