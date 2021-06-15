#include<bits/stdc++.h>
using namespace std;
int n,m,i,nn,l,r,k,max1,min1;
int a[200],sum[200];
int f[200][200][20],ff[200][200][20];
int MO(int x){return (x%10+10)%10;}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<n;i++)a[n+i]=a[i];
	nn=n*2-1;
	for(int i=1;i<=nn;i++)sum[i]=sum[i-1]+a[i];
	for(int i=0;i<200;i++)
		for(int j=0;j<200;j++)
			for(int k=0;k<20;k++){
				f[i][j][k]=-10000000;
				ff[i][j][k]=10000000;
			}
	for(int i=1;i<=n;i++)
		for(int l=1;l<=nn-i+1;l++){
			r=l+i-1;
			for(int j=1;j<=m;j++){
				if(j==1){
					f[l][r][1]=MO(sum[r]-sum[l-1]);
					ff[l][r][1]=MO(sum[r]-sum[l-1]);
					continue;
				}
				for(int k=l;k<=r;k++){
					if(f[l][k-1][j-1]>=0)
						f[l][r][j]=max(f[l][r][j],f[l][k-1][j-1]*MO(sum[r]-sum[k-1]));
					if(ff[l][k-1][j-1]<10000000)
					ff[l][r][j]=min(ff[l][r][j],ff[l][k-1][j-1]*MO(sum[r]-sum[k-1]));
				}
			}
		}
	max1=-100000000;
	min1=100000000;
	for(int i=1;i<=n;i++){
		max1=max(max1,f[i][i+n-1][m]);
		min1=min(min1,ff[i][i+n-1][m]);
	}
	printf("%d\n%d\n",min1,max1);
	return 0;
}
					
