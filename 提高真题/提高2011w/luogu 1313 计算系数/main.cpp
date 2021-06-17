#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL a,b,k,n,m,c[1100];
LL gcd(LL x,LL y){
    if(y==0)return x;
    return gcd(y,x%y);
}
int main(){
    cin>>a>>b>>k>>n>>m;
    for(int i=1;i<=n;i++)c[i]=k-i+1;
    for(int i=1;i<=n;i++){
        LL x=i;
        for(int j=1;j<=n;j++){
            LL g=gcd(x,c[j]);
            x/=g;
            c[j]/=g;
        }
    }
    LL ans=1;
    for(int i=1;i<=n;i++)ans=ans*a%10007;
    for(int i=1;i<=m;i++)ans=ans*b%10007;
    for(int i=1;i<=n;i++)ans=ans*c[i]%10007;
    cout<<ans<<endl;
    return 0;
}
