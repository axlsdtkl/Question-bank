#include<cstdio>
int lo,n,m,l,r,mid,i;
int a[60000];
int work(int x)
{
	int st,sum,i;
	st=0;
	sum=0;
	for(i=1;i<=n;i++)
	if(a[i]-st<x)sum++;
	else st=a[i];
	if(lo-st<x)sum++;
	if(sum<=m)return 1;
	return 0;
}
int main()
{
	scanf("%d%d%d",&lo,&n,&m);
	for(i=1;i<=n;i++)scanf("%d",&a[i]);
	l=0;r=lo+1;
	while(l+1<r)
	{
		mid=(l+r)/2;
		if(work(mid))l=mid;else r=mid;
	}
	printf("%d\n",l);
	return 0;
}