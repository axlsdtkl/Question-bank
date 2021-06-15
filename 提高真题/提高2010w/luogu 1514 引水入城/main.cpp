#include<bits/stdc++.h>
using namespace std;
struct data{
    int l,r;
}b[600][600],c[600];
int flag[600][600],a[600][600],f[600];
int n,m;
int dx[4]={-1,0,0,1};
int dy[4]={0,1,-1,0};
bool cmp(data a,data b){
    return a.l<b.l;
}
data dfs(int x,int y){
    if(flag[x][y]==1){
        return b[x][y];
    }
    flag[x][y]=1;
    if(x==n)b[x][y].l=b[x][y].r=y;
    else{
        b[x][y].l=10000;
        b[x][y].r=0;
    }
    for(int i=0;i<4;i++){
        int xx=x+dx[i];
        int yy=y+dy[i];
        if(xx<1||xx>n||yy<1||yy>m)continue;
        if(a[xx][yy]>=a[x][y])continue;
        data p=dfs(xx,yy);
        b[x][y].l=min(b[x][y].l,p.l);
        b[x][y].r=max(b[x][y].r,p.r);
    }
    return b[x][y];
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    int cnt=0;
    for(int i=1;i<=m;i++)
        b[1][i]=dfs(1,i);
    for(int i=1;i<=m;i++)if(b[n][i].l==0)cnt++;
    if(cnt>0){
        cout<<0<<endl;
        cout<<cnt<<endl;
        return 0;
    }
    cout<<1<<endl;
    for(int i=1;i<=m;i++)c[i]=b[1][i];
    sort(c+1,c+m+1,cmp);
    memset(f,42,sizeof(f));
    f[0]=0;
    for(int i=1;i<=m;i++){
        for(int j=0;j<i;j++){
            if(c[i].l-1<=c[j].r)f[i]=min(f[i],f[j]+1);
        }
    }
    int ans=1000000;
    for(int i=1;i<=m;i++){
        if(c[i].r==m)ans=min(ans,f[i]);
    }
    cout<<ans<<endl;
    return 0;
}
