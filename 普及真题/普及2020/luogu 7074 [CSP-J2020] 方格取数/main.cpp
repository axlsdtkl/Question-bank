#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1100;
ll n,m;
ll a[N][N],f[N][N],b[N][N],c[N][N];
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    memset(f,-42,sizeof(f));
    memset(b,-42,sizeof(b));
    memset(c,-42,sizeof(c));
    f[1][1]=a[1][1];
    for(int i=2;i<=n;i++)f[i][1]=f[i-1][1]+a[i][1];
    for(int i=2;i<=m;i++){
        for(int j=1;j<=n;j++){
            f[j][i]=f[j][i-1]+a[j][i];
        }
        for(int j=1;j<=n;j++){
            b[j][i]=max(b[j-1][i]+a[j][i],f[j][i]);
        }
        for(int j=n;j>=1;j--){
            c[j][i]=max(c[j+1][i]+a[j][i],f[j][i]);
        }
        for(int j=1;j<=n;j++)f[j][i]=max(b[j][i],c[j][i]);
    }
    cout<<f[n][m]<<endl;
    return 0;
}
