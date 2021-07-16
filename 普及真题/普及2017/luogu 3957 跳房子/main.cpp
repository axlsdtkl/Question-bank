#include<bits/stdc++.h>
using namespace std;
const int N=600000;
typedef long long ll;
struct data{
    ll pos,f;
}q[N];
ll pos[N],score[N],f[N];
ll n,d,k,l,r;
ll check(ll mid){
    ll left=max(1LL,d-mid);
    ll right=d+mid;
    memset(f,-42,sizeof(f));
    pos[0]=0;
    f[0]=0;
    ll l=1;
    ll r=0;
    ll mark=-1;
    for(int i=1;i<=n;i++){
        while(mark+1<i&&pos[mark+1]+left<=pos[i]){
            while(r>=l&&f[mark+1]>=q[r].f)
                r--;
            r++;
            mark++;
            q[r].pos=pos[mark];
            q[r].f=f[mark];
        }
        while(l<=r&&q[l].pos<pos[i]-right)l++;
        if(r>=l)f[i]=q[l].f+score[i];
        if(f[i]>=k)return 1;
    }
    return 0;
}
int main(){
    cin>>n>>d>>k;
    for(int i=1;i<=n;i++)cin>>pos[i]>>score[i];
    l=0;
    r=pos[n];
    while(l+1<r){
        ll mid=(l+r)>>1;
        if(check(mid))r=mid;
        else l=mid;
    }
    if(r==pos[n])cout<<-1<<endl;
    else cout<<r<<endl;
    return 0;
}
