#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=310000;
const ll MO=1000000007;
ll n,m,fa[N],size[N],fac[N],inf[N],ans[N];
ll last_ans,op,x,y;
ll ksm(ll x,ll y){
    ll res=1;
    while(y){
        if(y&1)res=res*x%MO;
        x=x*x%MO;
        y>>=1;
    }
    return res;
}
ll inv_p(ll x){return ksm(x,MO-2);}
void init_fac(ll n){
    fac[0]=1;
    for(int i=1;i<=n;i++)fac[i]=fac[i-1]*i%MO;
    inf[n]=inv_p(fac[n]);
    for(int i=n;i>=1;i--)inf[i-1]=inf[i]*i%MO;
}
ll comb(ll a,ll b){
    return fac[a]*inf[b]%MO*inf[a-b]%MO;
}
ll getfa(ll x){
    if(fa[x]==x)return x;
    return fa[x]=getfa(fa[x]);
}
void modify(ll x,ll y){
    x=getfa(x);
    y=getfa(y);
    size[y]+=size[x];
    fa[x]=y;
    ans[y]=ans[y]*ans[x]%MO*comb(size[y]-1,size[x])%MO;
}
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++)fa[i]=i,size[i]=1;
    init_fac(n);
    for(int i=0;i<n;i++)ans[i]=1;
    while(m--){
        cin>>op;
        if(op==1){
            cin>>x>>y;
            x=(x+last_ans)%n;
            y=(y+last_ans)%n;
            modify(x,y);
        }else{
            cin>>x;
            x=(x+last_ans)%n;
            x=getfa(x);
            cout<<(last_ans=ans[x])<<endl;
        }
    }
}
