#include <bits/stdc++.h>
using namespace std;
int f[110][110],n,m,a[110];
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    //三层for循环，暴力枚举用了前I种花，总数为j的情况下，方案数为多少
    f[0][0]=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<=m;j++){
            for(int k=0;k<=a[i+1];k++){
                if(j+k>m)continue;
                f[i+1][j+k]+=f[i][j];
                f[i+1][j+k]%=1000007;
            }
        }
    }
    
    
    cout<<f[n][m]<<endl;
    return 0;
}
