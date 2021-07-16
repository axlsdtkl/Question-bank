#include<bits/stdc++.h>
using namespace std;
int n,k,p,price,color[210000],sum[60],ans,t;
int main(){
    cin>>n>>k>>p;
    for(int i=1;i<=n;i++){
        cin>>color[i]>>price;
        if(price<=p){
            for(int j=i;j>t;j--)sum[color[j]]++;
            t=i;
            ans+=sum[color[i]]-1;
        }else ans+=sum[color[i]];
    }
    cout<<ans<<endl;
    return 0;
}
