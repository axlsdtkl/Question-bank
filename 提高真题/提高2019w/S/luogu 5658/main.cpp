#include<bits/stdc++.h>
using namespace std;
const int N=510000;
typedef long long ll;
char s[N];
ll n,top,ans;
vector<ll>e[N];
ll f[N],h[N],last[N],sum[N],fa[N];
void dfs(ll x){
    ll temp=0;
    if(s[x]=='('){
        top++;
        h[top]=x;
    }else{
        if(top){
            temp=h[top];
            top--;
            last[x]=last[fa[temp]]+1;
        }
    }
    sum[x]=last[x]+sum[fa[x]];
    ll nn=e[x].size();
    for(int i=0;i<nn;i++){
        int y=e[x][i];
        dfs(y);
    }
    if(temp)top++,h[top]=temp;
    else if(top>0)top--;
}
int main(){
    cin>>n;
    cin>>(s+1);
    for(int i=2;i<=n;i++){
        cin>>fa[i];
        e[fa[i]].push_back(i);
    }
    dfs(1);
    for(int i=1;i<=n;i++)ans^=((ll)i*sum[i]);
    cout<<ans<<endl;
    return 0;
}
