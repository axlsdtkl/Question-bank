#include<bits/stdc++.h>
using namespace std;
const int N=210000;
int n,a[N],cnt,b[N];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    b[1]=1;
    cnt=1;
    for(int i=2;i<=n;i++){
        if(a[i]==a[cnt])b[cnt]++;
        else cnt++,a[cnt]=a[i],b[cnt]=1;
    }
    if(cnt==1){
        cout<<-1<<endl;
        return 0;
    }
    if(cnt==2){
        if(a[2]%a[1]!=a[1]%a[2])cout<<a[2]%a[1]<<endl;
        else if(b[1]+b[2]==2)cout<<-1<<endl;
        else cout<<0<<endl;
        return 0;
    }
    if(cnt>2){
        cout<<max(a[cnt-2],a[cnt]%a[cnt-1])<<endl;
        return 0;
    }
    return 0;
}
