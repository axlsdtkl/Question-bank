#include<bits/stdc++.h>
using namespace std;
int n,m,k,s,t,x,y,z;
int c[110];
int g[110][110],f[110][110];
int main(){
    cin>>n>>k>>m>>s>>t;
    for(int i=1;i<=n;i++)cin>>c[i];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            f[i][j]=(1<<30)-1;
        }
    }
    for(int i=1;i<=k;i++){
        for(int j=1;j<=k;j++){
            cin>>g[i][j];
        }
    }
    if(c[s]==c[t]){
        cout<<-1<<endl;
        return 0;
    }
    for(int i=1;i<=m;i++){
        cin>>x>>y>>z;
        if(g[c[y]][c[x]]==0&&c[x]!=c[y])f[x][y]=min(f[x][y],z);
        if(g[c[x]][c[y]]==0&&c[x]!=c[y])f[y][x]=min(f[y][x],z);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
            }
        }
    }
    if(f[s][t]>10000000)cout<<-1<<endl;
    else cout<<f[s][t]<<endl;
    return 0;
}
