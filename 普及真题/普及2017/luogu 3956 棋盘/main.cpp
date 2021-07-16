#include<bits/stdc++.h>
using namespace std;
int n,m,i,x,y,z,ans;
int a[110][110],f[110][110][3];
int dx[4]={-1,0,0,1};
int dy[4]={0,-1,1,0};
void dfs(int x,int y,int z,int cnt){
    int xx,yy;
    if(cnt>=f[x][y][z])return;
    f[x][y][z]=cnt;
    for(int i=0;i<4;i++){
        xx=x+dx[i];yy=y+dy[i];
        if(a[x][y]>=0&&a[x][y]<=1){
            if(z==0){
                if(a[xx][yy]==0)dfs(xx,yy,0,cnt);
                if(a[xx][yy]==1)dfs(xx,yy,1,cnt+1);
                if(a[xx][yy]==2){
                    dfs(xx,yy,0,cnt+2);
                    dfs(xx,yy,1,cnt+3);
                }
            }
            if(z==1){
                if(a[xx][yy]==0)dfs(xx,yy,0,cnt+1);
                if(a[xx][yy]==1)dfs(xx,yy,1,cnt);
                if(a[xx][yy]==2){
                    dfs(xx,yy,0,cnt+3);
                    dfs(xx,yy,1,cnt+2);
                }
            }
        }
        else if(a[x][y]==2){
            if(z==0){
                if(a[xx][yy]==0)dfs(xx,yy,0,cnt);
                if(a[xx][yy]==1)dfs(xx,yy,1,cnt+1);
            }
            if(z==1){
                if(a[xx][yy]==0)dfs(xx,yy,0,cnt+1);
                if(a[xx][yy]==1)dfs(xx,yy,1,cnt);
            }
        }
    }
}
int main(){
    scanf("%d%d",&n,&m);
    memset(a,-1,sizeof(a));
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)a[i][j]=2;
    memset(f,42,sizeof(f));
    for(int i=1;i<=m;i++)scanf("%d%d%d",&x,&y,&z),a[x][y]=z;
    dfs(1,1,a[1][1],0);
    ans=min(f[n][n][0],f[n][n][1]);
    if(ans>10000000)ans=-1;
    printf("%d\n",ans);
    return 0;
}