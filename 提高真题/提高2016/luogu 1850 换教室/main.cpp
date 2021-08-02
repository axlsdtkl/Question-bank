#include<bits/stdc++.h>
using namespace std;
const int N=2100;
double p[N],f[N][N],dp[N][N][2];
int a[N][N],c[N],d[N];
int n,m,v,e,a1,b1,c1;
int main(){
    cin>>n>>m>>v>>e;
    for(int i=1;i<=n;i++)cin>>c[i];
    for(int i=1;i<=n;i++)cin>>d[i];
    for(int i=1;i<=n;i++)cin>>p[i];
    memset(f,127,sizeof(f));
    for(int i=1;i<=v;i++)f[i][i]=0;
    for(int i=1;i<=e;i++){
        cin>>a1>>b1>>c1;
        f[a1][b1]=f[b1][a1]=min(f[a1][b1],(double)c1);
    }
    for(int k=1;k<=v;k++){
        for(int i=1;i<=v;i++){
            for(int j=1;j<=v;j++){
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
            }
        }
    }
    memset(dp,127,sizeof(dp));
    dp[1][0][0]=dp[1][1][1]=0;
    for(int i=2;i<=n;i++){
        for(int j=0;j<=min(m,i);j++){
            dp[i][j][0]=min(dp[i-1][j][0]+f[c[i-1]][c[i]],dp[i-1][j][1]+f[d[i-1]][c[i]]*p[i-1]+f[c[i-1]][c[i]]*(1-p[i-1]));
            if(j!=0)
            dp[i][j][1]=min(dp[i-1][j-1][0]+f[c[i-1]][d[i]]*p[i]+f[c[i-1]][c[i]]*(1-p[i]),dp[i-1][j-1][1]+f[c[i-1]][c[i]]*(1-p[i-1])*(1-p[i])+f[c[i-1]][d[i]]*(1-p[i-1])*p[i]+f[d[i-1]][c[i]]*(1-p[i])*p[i-1]+f[d[i-1]][d[i]]*p[i-1]*p[i]);
        }
    }
    double ans=99999999;
    for(int i=0;i<=m;i++){
        ans=min(ans,dp[n][i][0]);
        ans=min(ans,dp[n][i][1]);
    }
    printf("%.2lf\n",ans);
    return 0;
}
