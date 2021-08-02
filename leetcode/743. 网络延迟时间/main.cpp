class Solution {
public:
    struct edge{
        int y,z;
    };
    struct node{
        int id,d;
        bool operator<(const node &up)const{
            return d>up.d;
        }
    }; 
    priority_queue<node>q;
    vector<edge>e[110];
    int ans,flag[110],dist[110];
    void dijkstra(int s){
        memset(dist,42,sizeof(dist));dist[s]=0;
        q.push({s,0});
        while(q.size()){
            node now=q.top();
            q.pop();
            int x=now.id;
            if(now.d>dist[x])continue;
            for(int i=0;i<e[x].size();i++){
                int y=e[x][i].y;
                if(dist[x]+e[x][i].z<dist[y]){
                    dist[y]=dist[x]+e[x][i].z;
                    q.push({y,dist[y]});
                }
            }
        }
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        for(int i=0;i<times.size();i++){
            int x=times[i][0],y=times[i][1],z=times[i][2];
            e[x].push_back({y,z});
        }
        dijkstra(k);
        for(int i=1;i<=n;i++){
            if(dist[i]>10000000)return -1;
        }
        for(int i=1;i<=n;i++)ans=max(ans,dist[i]);
        return ans;
    }
};