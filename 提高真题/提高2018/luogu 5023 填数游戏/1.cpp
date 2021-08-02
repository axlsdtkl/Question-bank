#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MO=1000000007;
ll a[10][10]={
    {0,0,0,0,0,0,0},
    {0,2,4},
    {0,0,12,36},
    {0,0,0,112,336},
    {0,0,0,0,912,2688},
    {0,0,0,0,0,7136,21312},
    {0,0,0,0,0,0,56768,170112},
    {0,0,0,0,0,0,0,453504,1360128},
    {0,0,0,0,0,0,0,0,3626752,10879488}
};
ll n,m;
ll ksm(ll a,ll b){
    ll res=1;
    while(b){
        if(b&1)res=res*a%MO;
        a=a*a%MO;
        b>>=1;
    }
    return res;
}
int main(){
    cin>>n>>m;
    if(n>m)swap(n,m);
    if(n==1)cout<<ksm(2,m)<<endl;
    else if(n==m||n+1==m){
        cout<<a[n][m]<<endl;
    }else cout<<a[n][n+1]*ksm(3,m-n-1)%MO<<endl;
    return 0;
}
