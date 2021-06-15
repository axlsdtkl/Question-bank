#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
int a[50],b[50],c[50],f[50][50][7][50];
int n,m,len1,r,cnt,len;
char s1[200];
int fc(int a[50],int b[50]){
	for(int i=50;i>=1;i--){
		if(a[i]>b[i])return 0;
		if(a[i]<b[i])return 1;
	}
	return 1;
}
int main(){
	freopen("1.in","r",stdin);
	cin>>n>>m;
	m++;
	cin>>(s1+1);
	len1=strlen(s1+1);
	for(int i=1;i<=len1;i++)
		for(int j=i;j<=len1;j++){
			int cnt=0;
			for(int k=j;k>=i;k--)cnt++,f[i][j][1][cnt]=s1[k]-'0';
		}
	for(int i=1;i<=len1;i++){
		for(int j=1;j<=len1-i+1;j++){
			r=j+i-1;
			for(int k=2;k<=m;k++)
				for(int l=j;l<=r-1;l++){
					for(int ll=1;ll<=50;ll++)a[ll]=f[j][l][k-1][ll];
					for(int ll=1;ll<=50;ll++)b[ll]=0;
					int cnt=0;
					for(int ll=r;ll>=l+1;ll--)cnt++,b[cnt]=s1[ll]-'0';
					for(int ll=1;ll<=50;ll++)c[ll]=0;
					for(int x=1;x<=50;x++)
						for(int y=1;y<=50;y++){
							if(x+y-1>50)continue;
							c[x+y-1]+=a[x]*b[y];
						}
					for(int ll=1;ll<=49;ll++)c[ll+1]+=c[ll]/10,c[ll]%=10;
					if(fc(f[j][r][k],c)==1)
						for(int ll=1;ll<=50;ll++)f[j][r][k][ll]=c[ll];
				}
		}
	}
	len=50;
	while(f[1][len1][m][len]==0&&len>1)len--;
	for(int i=len;i>0;i--)cout<<f[1][len1][m][i];
	return 0;
}