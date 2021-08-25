class Solution {
public:
    int ans[20],n;
    vector<vector<int>>fin;
    vector<vector<int>>graph1;
    void dfs(int now,int cnt){
        ans[cnt]=now;
        if(now==n-1){
            vector<int>res;
            for(int i=1;i<=cnt;i++)res.push_back(ans[i]);
            fin.push_back(res);
            return;
        }
        int m=graph1[now].size();
        for(int i=0;i<m;i++){
            dfs(graph1[now][i],cnt+1);
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        graph1=graph;
        n=graph.size();
        dfs(0,1);
        return fin;
    }
};