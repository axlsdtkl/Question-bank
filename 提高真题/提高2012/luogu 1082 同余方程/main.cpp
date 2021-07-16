#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,b,x,y;
void exgcd(ll a,ll b,ll &x,ll &y){
    if(b==0){
        x=1;y=0;
        return;
    }else exgcd(b,a%b,x,y);
    ll xx=y,yy=x-a/b*y;
    x=xx;y=yy;
}
int main(){
    cin>>a>>b;
    exgcd(a,b,x,y);
    if(x>0)x%=b;
    else{
        ll sz=(-x)/b+1;
        x+=sz*b;
    }
    cout<<x<<endl;
    return 0;
}
