#include<bits/stdc++.h>
using namespace std;
char s[200];
int a[10][10],f[10];
int ans[200];
int n,len,js,x,y;
int main(){
	scanf("%s%d",s+1,&n);
	for(int i=0;i<=9;i++)a[i][i]=1;
	for(int i=1;i<=n;i++){
		scanf("%d%d",&x,&y);
		a[x][y]=1;
	}
	for(int k=0;k<=9;k++)
		for(int i=0;i<=9;i++)
			for(int j=0;j<=9;j++)
				if(a[i][k]+a[k][j]==2)a[i][j]=1;
	for(int i=0;i<=9;i++)
		for(int j=0;j<=9;j++)
			if(a[i][j])f[i]++;
	ans[1]=1;
	len=strlen(s+1);
	for(int i=1;i<=len;i++){
		x=s[i]-'0';
		for(int j=1;j<=100;j++)ans[j]*=f[x];
		for(int j=1;j<=100;j++)ans[j+1]+=ans[j]/10,ans[j]%=10;
	}
	js=100;
	while(js>1&&ans[js]==0)js--;
	for(int i=js;i>0;i--)printf("%d",ans[i]);
	printf("\n");
	return 0;
}
	
