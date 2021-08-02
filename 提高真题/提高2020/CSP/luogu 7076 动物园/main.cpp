#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
ll n,m,c,k,x,y,z,ans;
vector<ll>e[100];
vector<ll>ha[1000000];
map<ll,bool>ma;
int main(){
    cin>>n>>m>>c>>k;
    for(int i=1;i<=n;i++)cin>>y,x|=y;
    for(int i=1;i<=m;i++){
        cin>>y>>z;
        e[y].push_back(z);
    }
    for(int i=0;i<=63;i++){
        if((x>>i)&1){
            ll nn=e[i].size();
            for(int j=0;j<nn;j++){
                ll z=e[i][j];
                ll zz=z%1000000;
                ha[zz].push_back(z);
            }
        }
    }
    for(int i=0;i<k;i++){
        int yes=1;
        int nn=e[i].size();
        for(int j=0;j<nn;j++){
            ll z=e[i][j];
            int mm=ha[z%1000000].size();
            int find=0;
            for(int ii=0;ii<mm;ii++)if(ha[z%1000000][ii]==z)find=1;
            if(find==0)yes=0;
        }
        if(yes==1)ans++;
    }
    if(ans==64){
        if(n==0)cout<<"18446744073709551616"<<endl;
        else{
            ll ansx=1ll<<63;
            ansx-=n;
            ansx+=1ll<<63;
            cout<<ansx<<endl;
        }
        return 0;
    }
    ll ansx=1;
    cout<<(ansx<<ans)-n<<endl;
    return 0;
}
