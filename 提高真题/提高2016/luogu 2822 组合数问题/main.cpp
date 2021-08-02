#include<bits/stdc++.h>
using namespace std;
const int N=2100;
int f[N][N],t,k,g[N][N],x,y;
int main(){
    cin>>t>>k;
    f[0][0]=1;
    for(int i=1;i<=2000;i++){
        f[i][0]=1;
        for(int j=1;j<=i;j++){
            f[i][j]=f[i-1][j-1]+f[i-1][j];
            f[i][j]%=k;
            if(f[i][j]==0)g[i][j]=1;
        }
    }
    for(int i=1;i<=2000;i++){
        g[i][0]+=g[i-1][0];
        for(int j=1;j<i;j++){
            g[i][j]=g[i][j-1]+g[i-1][j]-g[i-1][j-1]+g[i][j];
        }
        g[i][i]=g[i][i-1]+g[i][i];
    }
    while(t--){
        cin>>x>>y;
        y=min(x,y);
        cout<<g[x][y]<<endl;
    }
    return 0;
}
