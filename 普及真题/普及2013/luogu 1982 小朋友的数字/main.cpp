#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1100000;
ll read(){
    char ch=getchar();
    ll y=1;
    ll x=0;
    while(ch<'0'||ch>'9'){
        if(ch=='-')y=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*y;
}
ll a[N],b[N],c[N],d[N];
ll n,p,max1,ans,ans1,flag;
int main(){
    cin>>n>>p;
    for(int i=1;i<=n;i++)a[i]=read();
    c[1]=b[1]=a[1];
    max1=a[1];
    for(int i=2;i<=n;i++){
        max1=max(max1+a[i],a[i]);
        b[i]=max1;
        c[i]=max(b[i],c[i-1]);
    }
    d[1]=c[1];
    ans1=d[1];
    max1=d[1]+c[1];
    for(int i=2;i<=n;i++){
        d[i]=max1;
        if(flag==0)max1=max(max1,d[i]+c[i]);
        else max1=(d[i]+c[i]);
        if(flag==1){
            max1%=p;
        }else if(max1>=ans1){
            flag=1;
            max1%=p;
        }
    }
    if(flag==0)cout<<ans1%p<<endl;
    else cout<<d[n]%p<<endl;
    return 0;
}
