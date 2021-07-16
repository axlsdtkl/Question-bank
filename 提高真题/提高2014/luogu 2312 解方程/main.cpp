//luogu 2312
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MO=1000000007;
const ll N=110;
queue<ll>q;
ll n,m,a[N];
ll read(){
    char ch=getchar();
    ll x=0,y=1;
    while(ch<'0'||ch>'9'){
        if(ch=='-')y=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x*10+ch-'0')%MO;
        ch=getchar();
    }
    return x*y;
}
ll check(ll x){
    ll res=a[n];
    for(int i=n-1;i>=0;i--){
        res=res*x+a[i];
        res%=MO;
    }
    return res;
}
int main(){
    cin>>n>>m;
    for(int i=0;i<=n;i++)a[i]=read();
    for(int i=1;i<=m;i++){
        if(check(i)==0)q.push(i);
    }
    cout<<q.size()<<endl;
    ll num=q.size();
    for(int i=0;i<num;i++){
        cout<<q.front()<<endl;
        q.pop();
    }
    return 0;
}
