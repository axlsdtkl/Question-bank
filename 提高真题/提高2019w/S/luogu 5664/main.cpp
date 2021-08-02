#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MO=998244353;
const ll N=110;
const ll M=2100;
ll n,m,sum[N][M],f[N][M*2],g[N][N],a[N][M],ans1;
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
            sum[i][0]=(sum[i][0]+a[i][j])%MO;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            sum[i][j]=(sum[i][0]-a[i][j]+MO)%MO;
        }
    }
    ll ans=0;
    for(int col=1;col<=m;col++){
        memset(f,0,sizeof(f));
        f[0][n+1]=1;
        for(int i=1;i<=n;i++){
            for(int j=n+1-i;j<=n+1+i;j++){
                f[i][j]=(f[i-1][j]+f[i-1][j-1]*a[i][col]%MO+f[i-1][j+1]*sum[i][col]%MO)%MO;
            }
        }
        for(int j=1;j<=n;j++)ans=(ans+f[n][n+1+j])%MO;
    }
    g[0][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=n;j++){
            g[i][j]=(g[i-1][j]+(j>0?g[i-1][j-1]*sum[i][0]%MO:0))%MO;
        }
    }
    for(int j=1;j<=n;j++)ans1=(ans1+g[n][j]+MO)%MO;
    cout<<(ans1-ans+MO)%MO<<endl;
    return 0;
}
