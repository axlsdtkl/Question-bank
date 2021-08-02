#include<bits/stdc++.h>
using namespace std;
typedef __int128 ll;
const int N=100010,M=500010;
int n,m,d[N],v,in[N];
vector<int>e[N];
vector<int>ans;
queue<int>q;
ll gcd(ll a,ll b){
    return b==0?a:gcd(b,a%b);
}
ll lcm(ll a,ll b){
    return a/gcd(a,b)*b;
}
struct node{
    ll p,q;
    node(){
        p=0,q=1;
    }
    node operator *(const ll &rhs)const{
        node res;
        res.p=p,res.q=q*rhs;
        ll g=gcd(res.p,res.q);
        res.p/=g,res.q/=g;
        return res;
    }
    node operator +(const node &rhs)const{
        node res;
        res.q=lcm(q,rhs.q);
        res.p+=p*(res.q/q);
        res.p+=rhs.p*(res.q/rhs.q);
        ll g=gcd(res.p,res.q);
        res.p/=g,res.q/=g;
        return res;
    }
}val[N];
void print(ll x){
    if(x>9)print(x/10);
    putchar(x%10+'0');
}
void toposort(){
    for(int i=1;i<=n;i++){
        if(in[i]==0)q.push(i);
    }
    while(q.size()){
        int x=q.front();
        q.pop();
        if(d[x])val[x]=val[x]*d[x];
        for(int i=0;i<e[x].size();i++){
            int y=e[x][i];
            val[y]=val[y]+val[x];
            in[y]--;
            if(in[y]==0)q.push(y);
        }
    }
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        if(i<=m)val[i].p=1;
        cin>>d[i];
        if(d[i]==0)ans.push_back(i);
        for(int j=1;j<=d[i];j++){
            cin>>v;
            e[i].push_back(v);
            in[v]++;
        }
    }
    toposort();
    for(int i=0;i<ans.size();i++)print(val[ans[i]].p),putchar(' '),print(val[ans[i]].q),putchar('\n');
}
