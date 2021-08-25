class Solution {
public:
    int dist[110][110];
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        memset(dist,42,sizeof(dist));
        dist[src][0]=0;
        for(int i=1;i<=k+1;i++){
            for(int j=0;j<flights.size();j++){
                int x=flights[j][0];
                int y=flights[j][1];
                int z=flights[j][2];
                dist[y][i]=min(dist[y][i],dist[x][i-1]+z);
            }
        }
        int ans=INT_MAX;
        for(int i=0;i<=k+1;i++)ans=min(ans,dist[dst][i]);
        if(ans>100000000)ans=-1;
        return ans;
    }
};