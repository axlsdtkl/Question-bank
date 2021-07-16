#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=200005;
const ll MO=10007;
ll n,x,y,w[N],max1,max2,sum1,sum2,ans,maxx;
vector<ll>e[N];
int main(){
    cin>>n;
    for(int i=1;i<n;i++){
        cin>>x>>y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    for(int i=1;i<=n;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        max1=max2=0;
        sum1=sum2=0;
        for(int j=0;j<e[i].size();j++){
            int y=e[i][j];
            if(w[y]>max1)max2=max1,max1=w[y];
            else if(w[y]>max2)max2=w[y];
            sum1=(sum1+w[y])%MO;
            sum2=(sum2+w[y]*w[y])%MO;
        }
        ans=(ans+sum1*sum1-sum2+MO)%MO;
        maxx=max(maxx,max1*max2);
    }
    cout<<maxx<<" "<<ans<<endl;
    return 0;
}
