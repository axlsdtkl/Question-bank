#include<bits/stdc++.h>
using namespace std;
int n,a[1100000],ans;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    ans=a[1];
    for(int i=1;i<n;i++){
        ans+=(a[i]<a[i+1]?a[i+1]-a[i]:0);
    }
    cout<<ans<<endl;
    return 0;
    
}
