#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
queue<ll>q1,q2,q3;
ll n,m,q,u,v,t,len;
ll a[110000],ans[7300000];
int cmp(ll x,ll y){
    return x>y;
}
int getmax(){
    ll x=-100000000000ll;
    ll y=x;
    ll z=x;
    if(q1.size())x=q1.front();
    if(q2.size())y=q2.front();
    if(q3.size())z=q3.front();
    if(x>=y&&x>=z){
        q1.pop();
        return x;
    }else if(y>=x&&y>=z){
        q2.pop();
        return y;
    }else{
        q3.pop();
        return z;
    }
}
int main(){
    cin>>n>>m>>q>>u>>v>>t;
    double p=1.0*u/v;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++)q1.push(a[i]);
    for(int i=1;i<=m;i++){
        int x=getmax()+len;
        if(i%t==0)printf("%lld ",x);
        len+=q;
        int y=(int)(p*x);
        int z=x-y;
        q2.push(y-len);
        q3.push(z-len);
    }
    int cnt=0;
    while(q1.size()||q2.size()||q3.size())ans[++cnt]=getmax();
    printf("\n");
    for(int i=1;i<=cnt;i++){
        if(i%t==0)printf("%lld ",ans[i]+len);
    }
    return 0;
}
