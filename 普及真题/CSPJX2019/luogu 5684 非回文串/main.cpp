#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MO=1000000007;
ll n,odd,ans;
char s[2100];
ll fac[2100],sum[200];
ll power(ll a,ll b){
    ll res=1;
    while(b){
        if(b&1)res=res*a%MO;
        a=a*a%MO;
        b/=2;
    }
    return res;
}
int main(){
    cin>>n;
    cin>>s;
    fac[1]=1;
    for(int i=2;i<=n;i++){
        fac[i]=fac[i-1]*i%MO;
    }
    for(int i=0;i<n;i++){
        sum[s[i]]++;
    }
    for(int i='a';i<='z';i++){
        if(sum[i]%2==1){
            if(odd>0){
                cout<<fac[n]<<endl;
                return 0;
            }
            odd=i;
        }
    }
    ans=1;
    if(odd){
        ans=ans*sum[odd]%MO;
        sum[odd]--;
    }
    ans=ans*fac[n/2]%MO;
    for(int i='a';i<='z';i++){
        if(sum[i]>0){
            ans=ans*fac[sum[i]]%MO;
            ans=ans*power(fac[sum[i]/2],MO-2)%MO;
        }
    }
    cout<<(MO+fac[n]-ans)%MO<<endl;
    return 0;
}
