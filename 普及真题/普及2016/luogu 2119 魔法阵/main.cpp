#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=16000;
ll n,m;
ll num[41000];
ll v[N],a[N],b[N],c[N],d[N];
int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>num[i];
        v[num[i]]++;
    }
    for(int t=1;t*9<n-1;t++){
        ll sum=0;
        for(int vd=t*9+2;vd<=n;vd++){
            int vc=vd-t;
            int vb=vd-7*t-1;
            int va=vd-9*t-1;
            sum+=v[va]*v[vb];
            d[vd]+=v[vc]*sum;
            c[vc]+=v[vd]*sum;
        }
        sum=0;
        for(int va=n-t*9-1;va>=1;va--){
            int vb=va+2*t;
            int vc=va+8*t+1;
            int vd=va+9*t+1;
            sum+=v[vc]*v[vd];
            a[va]+=v[vb]*sum;
            b[vb]+=v[va]*sum;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<a[num[i]]<<" "<<b[num[i]]<<" "<<c[num[i]]<<" "<<d[num[i]]<<endl;
    }
    return 0;
}
