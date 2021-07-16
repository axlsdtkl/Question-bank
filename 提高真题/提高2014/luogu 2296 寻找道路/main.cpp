#include<bits/stdc++.h>
using namespace std;
const int N=11000;
int n,m,x,y,s,t,ans;
vector<int>e[N];
int vis[N],ok[N],flag[N],dist[N];
void bfs(int t){
    queue<int>q;
    q.push(t);
    vis[t]=1;
    while(q.size()){
        x=q.front();
        q.pop();
        for(int i=0;i<e[x].size();i++){
            int y=e[x][i];
            if(vis[y]==0){
                vis[y]=1;
                q.push(y);
            }
        }
    }
}
void spfa(int t){
    queue<int>q;
    memset(flag,0,sizeof(flag));flag[t]=1;
    memset(dist,42,sizeof(dist));
    if(ok[t]==0)return;
    dist[t]=0;
    q.push(t);
    while(q.size()){
        int x=q.front();
        q.pop();
        flag[x]=0;
        for(int i=0;i<e[x].size();i++){
            int y=e[x][i];
            if(ok[y]==0)continue;
            if(dist[x]+1<dist[y]){
                dist[y]=dist[x]+1;
                if(flag[y]==0){
                    flag[y]=1;
                    q.push(y);
                }
            }
        }
    }
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>x>>y;
        e[y].push_back(x);
    }
    cin>>s>>t;
    bfs(t);
    for(int i=1;i<=n;i++)ok[i]=vis[i];
    for(int i=1;i<=n;i++){
        if(vis[i]==0){
            for(int j=0;j<e[i].size();j++){
                int y=e[i][j];
                ok[y]=0;
            }
        }
    }
    spfa(t);
    if(dist[s]<1000000)ans=dist[s];else ans=-1;
    cout<<ans<<endl;
    return 0;
}
