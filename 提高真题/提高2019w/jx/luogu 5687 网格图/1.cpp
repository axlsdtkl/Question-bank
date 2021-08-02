#include<bits/stdc++.h>
using namespace std;
long long n,m,a[310000],b[310000],ans,l1,l2;
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=m;i++)cin>>b[i];
    sort(a+1,a+n+1);
    sort(b+1,b+m+1);
    ans=a[1]*(m-1)+b[1]*(n-1);
    l1=2;l2=2;
    while(l1<=n&&l2<=m){
        if(a[l1]<b[l2])ans+=a[l1]*(m-l2+1),l1++;
        else ans+=b[l2]*(n-l1+1),l2++;
    }
    cout<<ans<<endl;
    return 0;
}
