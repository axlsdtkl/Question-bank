#include<bits/stdc++.h>
using namespace std;
const int N=100005;
const int mod=998244353;
int n,m,Q,b,C,x;
int a[N],mul[N],idx[N],f[N],deg[N],k[N];
struct operation{
    int opt,pos,val;
    vector<int>g;
}T[N];
void calc(int u){
    if(mul[u]!=-1)return;
    if(T[u].opt==1)mul[u]=1;
    else if(T[u].opt==2)mul[u]=T[u].val;
    else if(T[u].opt==3){
        mul[u]=1;
        for(int i=0;i<(int)T[u].g.size();i++){
            int v=T[u].g[i];
            calc(v);
            mul[u]=1ll*mul[u]*mul[v]%mod;
        }
    }
}
void toposort(){
    queue<int>q;
    for(int i=1;i<=m;i++){
        if(deg[i]==0)q.push(i);
    }
    while(q.size()){
        int u=q.front();q.pop();
        if(T[u].opt==1)k[T[u].pos]=(k[T[u].pos]+1ll*f[u]*T[u].val)%mod;
        else if(T[u].opt==2)continue;
        else if(T[u].opt==3){
            for(int j=T[u].g.size()-1;j>=0;j--){
                int v=T[u].g[j];
                f[v]=(f[v]+f[u])%mod;
                f[u]=1ll*f[u]*mul[v]%mod;
                if(--deg[v]==0)q.push(v);
            }
        }
    }
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    cin>>m;
    for(int i=1;i<=m;i++){
        cin>>T[i].opt;
        if(T[i].opt==1)cin>>T[i].pos>>T[i].val;
        else if(T[i].opt==2)cin>>T[i].val;
        else if(T[i].opt==3){
            cin>>C;
            for(int j=1;j<=C;j++){
                cin>>x;
                T[i].g.push_back(x);
            }
        }
    }
    memset(mul,-1,sizeof(mul));
    for(int i=1;i<=m;i++)if(mul[i]==-1)calc(i);
    cin>>Q;
    for(int i=1;i<=Q;i++)cin>>idx[i];
    b=1;
    for(int i=Q;i>=1;i--){
        if(T[idx[i]].opt==1)f[idx[i]]=(f[idx[i]]+b)%mod;
        else if(T[idx[i]].opt==2)b=1ll*b*T[idx[i]].val%mod;
        else{
            f[idx[i]]=(f[idx[i]]+b)%mod;
            b=1ll*b*mul[idx[i]]%mod;
        }
    }
    for(int u=1;u<=m;u++){
        if(T[u].opt!=3)continue;
        for(int j=0;j<(int)T[u].g.size();j++){
            int v=T[u].g[j];
            deg[v]++;
        }
    }
    toposort();
    for(int i=1;i<=n;i++)printf("%lld ",(1ll*a[i]*b+k[i])%mod);
    puts("");
    return 0;
}
