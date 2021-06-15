#include<bits/stdc++.h>
using namespace std;
const int N=11000;
int a[N],b[N],c[N],d[N];
int n,x,y;
int ans=-1;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i]>>b[i]>>c[i]>>d[i];
    cin>>x >>y;
    for(int i=n;i>=1;i--){
        if(a[i]+c[i]>=x&&x>=a[i]&&b[i]+d[i]>=y&&y>=b[i]){
            ans=i;
            cout<<ans<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
    return 0;
    
}
