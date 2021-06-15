#include<cstdio>
#include<iostream>
using namespace std;
int x,y,z,n,xx,yy,a[10][10],f[10][10][10],max1;
int main(){
	freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	cin>>n;
	for(;;){
		cin>>x>>y>>z;
		if(x+y+z==0)break;
		a[x][y]=z;
	}
	for(int x=1;x<=n;x++)
		for(int y=1;y<=n;y++)
			for(int xx=x;xx<=n;xx++){
				yy=x+y-xx;
				if(yy<=0)continue;
				max1=max(f[x-1][y][xx-1],f[x-1][y][xx]);
				max1=max(max1,f[x][y-1][xx-1]);
				max1=max(max1,f[x][y-1][xx]);
				if(x==xx)f[x][y][xx]=max1+a[x][y];
				else f[x][y][xx]=max1+a[x][y]+a[xx][yy];
			}
	cout<<f[n][n][n]<<endl;
	return 0;
}