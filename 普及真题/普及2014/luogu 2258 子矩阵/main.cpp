#include<bits/stdc++.h>
using namespace std;
const int N=20;
int n,m,r,p,ans;
int a[N][N],b[N][N],f[N][N];
int row[N],c[N],d[N][N];
void init(){
    for(int i=1;i<=r;i++){
        for(int j=1;j<=m;j++){
            b[i][j]=a[row[i]][j];
        }
    }
    memset(c,0,sizeof(c));
    memset(d,0,sizeof(d));
    for(int i=1;i<=m;i++){
        for(int j=2;j<=r;j++){
            c[i]+=abs(b[j][i]-b[j-1][i]);
        }
    }
    for(int i=2;i<=m;i++){
        for(int j=1;j<i;j++){
            for(int k=1;k<=r;k++){
                d[j][i]+=abs(b[k][i]-b[k][j]);
            }
        }
    }
}
void work(){
    memset(f,42,sizeof(f));
    for(int i=1;i<=m;i++){
        for(int j=1;j<=p;j++){
            if(j==1){
                f[i][j]=c[i];
                continue;
            }
            for(int k=1;k<i;k++){
                f[i][j]=min(f[i][j],f[k][j-1]+d[k][i]+c[i]);
            }
        }
        ans=min(ans,f[i][p]);
    }
}
void dfs(int x,int y){
    if(x>n){
        if(y==r){
            init();
            work();
        }
        return;
    }
    row[y+1]=x;
    dfs(x+1,y+1);
    dfs(x+1,y);
}
int main(){
    cin>>n>>m>>r>>p;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    ans=1<<30;
    dfs(1,0);
    cout<<ans<<endl;
    return 0;
}
