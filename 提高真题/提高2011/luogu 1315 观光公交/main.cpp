#include<bits/stdc++.h>
using namespace std;
const int N=1100;
typedef long long LL;
LL n,m,k,x,y,z,ans,mark;
LL t[N],last[N],ti[N],num[N],f[N];
int main(){
    cin>>n>>m>>k;
    for(int i=2;i<=n;i++)cin>>t[i];
    for(int i=1;i<=m;i++){
        cin>>x>>y>>z;
        ans-=x;
        last[y]=max(last[y],x);
        num[z]++;
    }
    for(int i=2;i<=n;i++)ti[i]=max(ti[i-1],last[i-1])+t[i];
    while(k--){
        for(int i=n;i>=2;i--){
            if(last[i]>=ti[i])f[i]=num[i];
            else f[i]=num[i]+f[i+1];
        }
        LL max1=0;
        for(int i=2;i<=n;i++){
            if(f[i]>max1&&t[i]>0)max1=f[i],mark=i;
        }
        t[mark]--;
        for(int i=2;i<=n;i++)ti[i]=max(ti[i-1],last[i-1])+t[i];
    }
    for(int i=2;i<=n;i++)ans+=ti[i]*num[i];
    cout<<ans<<endl;
    return 0;
}
