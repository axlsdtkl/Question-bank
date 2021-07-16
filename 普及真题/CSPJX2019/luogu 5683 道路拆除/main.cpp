#include<bits/stdc++.h>
using namespace std;
const int N=3100;
struct node{
    int id,d;
    bool operator <(const node &x)const{
        return d>x.d;
    }
};
priority_queue<node>q;
int n,m,x,y,s1,t1,s2,t2,ans=1<<30;
vector<int>e[N];
int dist[N],dist1[N],dist2[N],dist3[N],flag[N];
void dijkstra(int S){
    memset(dist,42,sizeof(dist));
    dist[S]=0;
    q.push({S,0});
    memset(flag,0,sizeof(flag));
    while(q.size()){
        int x=q.top().id;
        q.pop();
        if(flag[x]==1)continue;
        flag[x]=1;
        for(int i=0;i<e[x].size();i++){
            int y=e[x][i];
            if(dist[x]+1<dist[y]){
                dist[y]=dist[x]+1;
                q.push({y,dist[y]});
            }
        }
    }
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>x>>y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    cin>>s1>>t1>>s2>>t2;
    dijkstra(1);
    for(int i=1;i<=n;i++)dist1[i]=dist[i];
    if(dist[s1]>t1||dist[s2]>t2){
        cout<<-1<<endl;
        return 0;
    }
    dijkstra(s1);
    for(int i=1;i<=n;i++)dist2[i]=dist[i];
    dijkstra(s2);
    for(int i=1;i<=n;i++)dist3[i]=dist[i];
    for(int i=1;i<=n;i++){
        if(dist1[i]+dist2[i]<=t1&&dist1[i]+dist3[i]<=t2){
            ans=min(ans,dist1[i]+dist2[i]+dist3[i]);
        }
    }
    cout<<m-ans<<endl;
    return 0;
}
