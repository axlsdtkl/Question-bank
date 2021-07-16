#include<bits/stdc++.h>
using namespace std;
const int N=50005;
typedef long long ll;
struct edge{
    ll o,d;
};
struct data{
    ll d,x;
}h[N];
queue<ll>q;
ll n,t,x,y,z,l,r,m,ok;
ll sta[N],ned[N],need[N],tim[N];
ll query[N],d[N],dist[N][20],f[N][20];
vector<edge>e[N];
int cmp1(data a,data b){
    return a.d<b.d;
}
bool dfs(ll x){
    bool yes=0;
    if(sta[x])return 1;
    for(int i=0;i<e[x].size();i++){
        ll y=e[x][i].o;
        if(d[y]<d[x])continue;
        yes=1;
        if(!dfs(y))return 0;
    }
    if(!yes)return 0;
    return 1;
}
void bfs(){
    q.push(1);
    d[1]=1;
    while(q.size()){
        ll x=q.front();q.pop();
        for(int i=0;i<e[x].size();i++){
            ll o=e[x][i].o,di=e[x][i].d;
            if(d[o])continue;
            d[o]=d[x]+1;
            dist[o][0]=di;
            f[o][0]=x;
            q.push(o);
        }
    }
    for(int i=1;i<=t;i++){
        for(int j=1;j<=n;j++){
            f[j][i]=f[f[j][i-1]][i-1];
            dist[j][i]=dist[j][i-1]+dist[f[j][i-1]][i-1];
        }
    }
}
bool check(ll lim){
    memset(sta,0,sizeof(sta));
    memset(need,0,sizeof(need));
    int atot=0,btot=0,ctot=0;
    for(int i=1;i<=m;i++){
        ll x=query[i];
        int cnt=0;
        for(int j=t;j>=0;j--){
            if(f[x][j]>1&&cnt+dist[x][j]<=lim){
                cnt+=dist[x][j];
                x=f[x][j];
            }
        }
        if(f[x][0]==1&&cnt+dist[x][0]<=lim){
            ++ctot;
            h[ctot]={lim-cnt-dist[x][0],x};
        }else sta[x]=1;
    }
    for(int i=0;i<e[1].size();i++){
        if(!dfs(e[1][i].o))need[e[1][i].o]=1;
    }
    sort(h+1,h+ctot+1,cmp1);
    for(int i=1;i<=ctot;i++){
        if(need[h[i].x]&&h[i].d<dist[h[i].x][0])
            need[h[i].x]=0;
        else tim[++atot]=h[i].d;
    }
    for(int i=0;i<e[1].size();i++){
        if(need[e[1][i].o])
            btot++,ned[btot]=dist[e[1][i].o][0];
    }
    sort(tim+1,tim+atot+1);
    sort(ned+1,ned+btot+1);
    ll i=1,j=1;
    while(i<=btot&&j<=atot){
        if(tim[j]>=ned[i])i++,j++;
        else j++;
    }
    if(i>btot)return 1;
    return 0;
}
int main(){
    cin>>n;
    t=log2(n);
    for(int i=1;i<n;i++){
        cin>>x>>y>>z;
        e[x].push_back({y,z});
        e[y].push_back({x,z});
        r+=z;
    }
    r++;
    bfs();
    cin>>m;
    for(int i=1;i<=m;i++){
        cin>>query[i];
    }
    l=-1;
    while(l+1<r){
        ll mid=(l+r)/2;
        if(check(mid))r=mid,ok=1;
        else l=mid;
    }
    if(ok==0)cout<<-1<<endl;
    else cout<<r<<endl;
    return 0;
}
