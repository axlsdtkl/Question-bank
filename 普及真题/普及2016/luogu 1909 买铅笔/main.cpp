#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,x[4],y[4],sum=100000000,t,hs;
    cin>>n;
    for(int i=0;i<3;i++){
        cin>>x[i]>>y[i];
        if((n%x[i])!=0) hs=n/x[i]+1;
        else hs=n/x[i];
        t=hs*y[i];
        sum=min(sum,t);
    }
    cout<<sum;
    return 0;
}
