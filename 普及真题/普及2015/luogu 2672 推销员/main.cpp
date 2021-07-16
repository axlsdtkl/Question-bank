#include<bits/stdc++.h>
using namespace std;

int n,sum[100010],f[100010],l[100010];
struct fam{
    int dis;
    int tir;
}h[100010];
bool comp(fam x,fam y){
    return x.tir>y.tir;
}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>h[i].dis;
    }
    for(int i=1;i<=n;i++){
        cin>>h[i].tir;
    }
    sort(h+1,h+1+n,comp);
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+h[i].tir;
    }
    for(int i=1;i<=n;i++){
        f[i]=max(f[i-1],2*h[i].dis);
    }
    for(int i=n;i>=1;i--){
        l[i]=max(l[i+1],h[i].tir+h[i].dis*2);
    }
    for(int i=1;i<=n;i++){
        cout<<max(sum[i]+f[i],sum[i-1]+l[i])<<endl;
    }
    return 0; 
}