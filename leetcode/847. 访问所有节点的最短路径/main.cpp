class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>> flag(n,vector<int>(1<<n));
        queue<tuple<int,int,int>>q;
        int ans;
        for(int i=0;i<n;i++){
            flag[i][1<<i]=1;
            q.push({i,1<<i,0});
        }
        while(q.size()){
            auto [x,y,z]=q.front();
            q.pop();
            if(y==(1<<n)-1){
                ans=z;
                break;
            }
            int m=graph[x].size();
            for(int i=0;i<m;i++){
                int yy=graph[x][i];
                if(flag[yy][(1<<yy)|y]==0){
                    flag[yy][(1<<yy)|y]=1;
                    q.push({yy,(1<<yy)|y,z+1});
                }
            }
        }
        return ans;
    }
};