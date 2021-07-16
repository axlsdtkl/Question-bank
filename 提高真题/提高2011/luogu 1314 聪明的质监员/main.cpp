#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=210000;
LL w[N],v[N],l[N],r[N],sumW[N],sumV[N];
LL n,m,s,le,ri,mid;
LL check(LL x){
    for(int i=1;i<=n;i++){
        if(w[i]>=x){
            sumW[i]=1;
            sumV[i]=v[i];
        }else sumW[i]=0,sumV[i]=0;
    }
    for(int i=2;i<=n;i++){
        sumW[i]+=sumW[i-1];
        sumV[i]+=sumV[i-1];
    }
    LL sum1=0,sum2=0,ans=0;
    for(int i=1;i<=m;i++){
        sum1=sumW[r[i]]-sumW[l[i]-1];
        sum2=sumV[r[i]]-sumV[l[i]-1];
        ans+=sum1*sum2;
    }
    return ans;
}
int main(){
    cin>>n>>m>>s;
    for(int i=1;i<=n;i++)cin>>w[i]>>v[i];
    for(int i=1;i<=m;i++)cin>>l[i]>>r[i];
    le=0;//>=
    ri=1000001;//<
    while(le+1<ri){
        mid=(le+ri)>>1;
        if(check(mid)>=s)le=mid;
        else ri=mid;
    }
    cout<<min(check(le)-s,s-check(ri))<<endl;
    return 0;
}
