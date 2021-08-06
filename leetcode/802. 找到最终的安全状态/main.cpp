class Solution {
public:
    vector<int>e[11000];
    vector<int>ans;
    int in[11000];
    queue<int>q;
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        for(int i=0;i<n;i++){
            int m=graph[i].size();
            for(int j=0;j<m;j++){
                e[graph[i][j]].push_back(i);
                in[i]++;
            }
        }
        for(int i=0;i<n;i++){
            if(in[i]==0)q.push(i);
        }
        while(q.size()){
            int x=q.front();
            q.pop();
            ans.push_back(x);
            for(int i=0;i<e[x].size();i++){
                int y=e[x][i];
                in[y]--;
                if(in[y]==0)q.push(y);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};