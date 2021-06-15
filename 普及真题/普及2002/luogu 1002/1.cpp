#include<bits/stdc++.h>
#define LL long long
LL n,m,x,y,f[100][100],i,j,xx,yy;
int flag[100][100];
int dx[8]={-2,-2,-1,-1,1,1,2,2};
int dy[8]={-1,1,-2,2,-2,2,-1,1};
int main(){
	scanf("%lld%lld%lld%lld",&n,&m,&x,&y);
	n++;m++;x++;y++;
	flag[x][y]=1;
	for(i=0;i<8;i++){
		xx=x+dx[i];yy=y+dy[i];
		if(xx<0||yy<0)continue;
		if(xx>n||yy>m)continue;
		flag[xx][yy]=1;
	}
	f[1][1]=1;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++){
			if(i+j==2)continue;
			if(flag[i][j]==0)
				f[i][j]=f[i-1][j]+f[i][j-1];
			}
	printf("%lld\n",f[n][m]);
	return 0;
}
