#include<bits/stdc++.h>
using namespace std;
double min1,max1,z;
int x,y,qw,cz,r,mark;
int a[110000],b[110000];
int main(){
	scanf("%d",&qw);
	scanf("%d%d",&a[1],&b[1]);
	r=1;
	for(;;){
		scanf("%d%d",&x,&y);
		if(x==-1)break;
		cz=(b[r]-y)/(x-a[r]);
		for(int i=a[r]+1;i<=x;i++){
			r++;
			a[r]=i;
			b[r]=b[r-1]-cz;
		}
	}
	scanf("%d",&x);
	while(b[r]>x){
		r++;a[r]=a[r-1]+1;b[r]=b[r-1]-x;
	}
	for(int i=1;i<=r;i++)if(a[i]==qw)mark=i;
	min1=-10000000;
	max1=10000000;
	for(int i=1;i<=r;i++){
		if(mark==i)continue;
		z=1.0*(a[1]*b[mark]-qw*b[mark]+a[i]*b[i]-a[1]*b[i]);
		if(b[mark]-b[i]>0)min1=max(min1,z/(b[mark]-b[i]));
		else max1=min(max1,z/(b[mark]-b[i]));
	}
	if(min1>max1)printf("NO SOLUTION\n");
		else if(min1>0)printf("%d\n",(int)(min1+0.999999));
			else if(max1<0)printf("%d\n",(int)(max1-0.999999));
				else printf("0\n");
	return 0;
}
	
