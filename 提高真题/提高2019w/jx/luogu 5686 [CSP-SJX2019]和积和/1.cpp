#include<cstring>
#include<iostream>
#include<cstdio>
using namespace std;
#define N 510000
#define mo 1000000007
long long n,x,sum1[N],sum2[N],sum12[N],sum22[N],sum3[N],ans;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x;
        sum1[i]=(sum1[i-1]+x)%mo;
        sum12[i]=(sum12[i-1]+sum1[i])%mo;
    }
    for(int i=1;i<=n;i++){
        cin>>x;
        sum2[i]=(sum2[i-1]+x)%mo;
        sum22[i]=(sum22[i-1]+sum2[i])%mo;
    }
    for(int i=1;i<=n;i++)sum3[i]=(sum3[i-1]+sum1[i]*sum2[i])%mo;
    for(int r=1;r<=n;r++){
        ans=ans+sum1[r]*sum2[r]%mo*r%mo;
        ans%=mo;
        ans=ans-sum1[r]*sum22[r-1]%mo+mo;
        ans%=mo;
        ans=ans-sum2[r]*sum12[r-1]%mo+mo;
        ans%=mo;
        ans=ans+sum3[r-1];
        ans%=mo;
    }
    cout<<ans<<endl;
    return 0;
}
