#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
ll n,k;
string dfs(ll n,ll k){
    if(n==1){
        if(k==0)return "0";
        else return "1";
    }else{
        ll sum=1ll<<(n-1);
        if(k<sum){
            string s=dfs(n-1,k);
            return "0"+s;
        }else{
            string s=dfs(n-1,(sum-1)-(k-sum));
            return "1"+s;
        }
    }
}
int main(){
    cin>>n>>k;
    cout<<dfs(n,k)<<endl;
    return 0;
}
