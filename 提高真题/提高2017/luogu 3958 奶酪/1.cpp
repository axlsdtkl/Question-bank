#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1100;
ll T,n,h,r,fa[N],x[N],y[N],z[N];
ll getfa(ll a){
    if(fa[a]==a)return a;
    return fa[a]=getfa(fa[a]);
}
void uni(ll a,ll b){
    ll fa1=getfa(a);
    ll fa2=getfa(b);
    if(fa1!=fa2)fa[fa2]=fa1;
}
ll dist(ll a,ll b){
    return (x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b])+(z[a]-z[b])*(z[a]-z[b]);
}
int main(){
    cin>>T;
    while(T--){
        cin>>n>>h>>r;
        for(int i=1;i<=n+2;i++)fa[i]=i;
        for(int i=1;i<=n;i++){
            cin>>x[i]>>y[i]>>z[i];
            if(z[i]-r<=0){
                uni(i,n+1);
            }
            if(z[i]+r>=h)uni(i,n+2);
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(dist(i,j)<=4*r*r)uni(i,j);
            }
        }
        ll fa1=getfa(n+1);
        ll fa2=getfa(n+2);
        if(fa1==fa2)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}
