#include<bits/stdc++.h>
using namespace std;
const int N=1100;
vector<int>e[N];
int a[N],in[N],d[N];
int n,m,nn,x,ans;
bool flag[N][N];
int main(){
    cin>>n>>m;
    while(m--){
        cin>>nn;
        for(int i=1;i<=nn;i++){
            cin>>a[i];
        }
        for(int i=2;i<=nn;i++){
            for(int j=a[i-1]+1;j<=a[i]-1;j++){
                for(int k=1;k<=nn;k++){
                    if(flag[j][a[k]])continue;
                    flag[j][a[k]]=1;
                    e[j].push_back(a[k]);
                    in[a[k]]++;
                }
            }
        }
    }
    queue<int>q;
    for(int i=1;i<=n;i++){
        if(in[i]==0)q.push(i),d[i]=1;
    }
    while(q.size()){
        x=q.front();
        q.pop();
        for(int i=0;i<e[x].size();i++){
            int y=e[x][i];
            in[y]--;
            if(in[y]==0){
                d[y]=d[x]+1;
                q.push(y);
            }
        }
    }
    for(int i=1;i<=n;i++)ans=max(ans,d[i]);
    cout<<ans<<endl;
    return 0;
}
