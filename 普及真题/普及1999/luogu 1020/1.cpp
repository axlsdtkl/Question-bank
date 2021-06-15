#include<bits/stdc++.h>
#define oo 1000000000
int f[110000],a[110000];
int i,l,r,mid,n;
int main(){
	//freopen("1.in","r",stdin);
	while(scanf("%d",&a[++n])!=EOF);
	f[0]=oo;
	for(i=1;i<=n;i++)f[i]=-oo;
	for(i=1;i<=n;i++){
		l=0;r=i;
		while(l+1<r){
			mid=(l+r)/2;
			if(f[mid]>=a[i])l=mid;
			else r=mid;
		}
		f[l+1]=a[i];
	}
	for(i=n;i>0;i--)if(f[i]>0)break;
	printf("%d\n",i);
	f[0]=0;
	for(i=1;i<=n;i++)f[i]=oo;
	for(i=1;i<=n;i++){
		l=0;r=i;
		while(l+1<r){
			mid=(l+r)/2;
			if(f[mid]<a[i])l=mid;
			else r=mid;
		}
		f[l+1]=a[i];
	}
	for(i=n;i>0;i--)if(f[i]<oo)break;
	printf("%d\n",i);
	return 0;
}
