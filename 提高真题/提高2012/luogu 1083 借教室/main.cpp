#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
#define N 1100000
struct arr{int x,y,z;}b[N];
int a[N],c[N];
int n,m,l,r,mid,i;
int work(int nn)
{
    int i,x,y,z;
    for(i=1;i<=n;i++)c[i]=0;
    for(i=1;i<=nn;i++)
    {
        x=b[i].x;y=b[i].y;z=b[i].z;
        c[y]+=x;c[z+1]-=x;
    }
    for(i=1;i<=n;i++)c[i]+=c[i-1];
    for(i=1;i<=n;i++)if(c[i]>a[i])return 0;
    return 1;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)scanf("%d",&a[i]);
    for(i=1;i<=m;i++)scanf("%d%d%d",&b[i].x,&b[i].y,&b[i].z);
    l=0;r=m+1;
    while(l+1<r)
    {
        mid=(l+r)/2;
        if(work(mid))l=mid;else r=mid;
    }
    if(l==m){printf("0\n");return 0;}
    printf("-1\n");
    printf("%d\n",l+1);
    return 0;
}