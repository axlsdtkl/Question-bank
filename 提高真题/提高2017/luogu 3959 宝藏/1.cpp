#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=12;
const int M=1<<N;
int n,m,dis[N+1][N+1],trans[M][M],POW[N+1],s,t,v;
ll f[N+1][M];
int main(){
    cin>>n>>m;
    memset(dis,42,sizeof(dis));
    for(int i=1;i<=m;i++){
        cin>>s>>t>>v;
        dis[s][t]=dis[t][s]=min(dis[s][t],v);
    }
    m=1<<n;
    POW[0]=1;
    for(int i=1;i<=n;i++)POW[i]=POW[i-1]*2;
    for(int i=0;i<m;i++){
        for(int j=i;j!=0;j=(j-1)&i){//枚举所有子集
            bool OK=true;
            ll temp=i^j;
            for(ll k=n-1;k>=0;k--){
                if(temp>=POW[k]){
                    int tmin=500000000;
                    for(int o=1;o<=n;o++){
                        if((POW[o-1]&j)==POW[o-1]){
                            tmin=min(tmin,dis[o][k+1]);
                        }
                    }
                    if(tmin>=500000000){
                        OK=false;
                        break;
                    }
                    trans[j][i]+=tmin;
                    temp-=POW[k];
                }
            }
            if(OK==false)trans[j][i]=500000000;
        }
    }
    memset(f,42,sizeof(f));
    for(int i=1;i<=n;i++)f[1][POW[i-1]]=0;
    for(int i=2;i<=n;i++){
        for(int j=0;j<m;j++){
            for(int k=j;k!=0;k=(k-1)&j){
                if(trans[k][j]!=500000000)
                    f[i][j]=min(f[i][j],f[i-1][k]+(i-1)*trans[k][j]);
            }
        }
    }
    ll ans=LONG_LONG_MAX;
    for(int i=1;i<=n;i++)ans=min(ans,f[i][m-1]);
    cout<<ans<<endl;
    return 0;
}
