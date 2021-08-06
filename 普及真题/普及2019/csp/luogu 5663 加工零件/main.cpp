#include<bits/stdc++.h>
using namespace std;
const int N=110000;
struct data{
    int p,t;
}q[1000000];
int n,m,ques,l,r,x,y;
int dist[N][2];
vector<int>e[N];
void bfs(int S){
    memset(dist,42,sizeof(dist));
    dist[S][0]=0;
    l=0;
    r=1;
    q[1].p=S;
    q[1].t=0;
    while(l<r){
        l++;
        int p=q[l].p;
        int t=q[l].t;
        for(int i=0;i<e[p].size();i++){
            int y=e[p][i];
            if(dist[p][t]+1<dist[y][1-t]){
                dist[y][1-t]=dist[p][t]+1;
                r++;
                q[r].p=y;
                q[r].t=1-t;
            }
        }
    }
}
int main(){
    cin>>n>>m>>ques;
    for(int i=1;i<=m;i++){
        cin>>x>>y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    bfs(1);
    while(ques--){
        cin>>x>>y;
        if(y%2==0){
            if(dist[x][0]<=y)cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }else{
            if(dist[x][1]<=y)cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }
    }
    return 0;
}
