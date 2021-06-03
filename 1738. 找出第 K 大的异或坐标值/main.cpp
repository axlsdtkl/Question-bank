class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        int m=matrix[0].size();
        int a[1100][1100]={};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                a[i+1][j+1]=matrix[i][j];
            }
        }
        vector<int>ans;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                a[i][j]=a[i-1][j]^a[i][j-1]^a[i-1][j-1]^a[i][j];
                ans.push_back(a[i][j]);
            }
        }
        sort(ans.begin(),ans.end());
        return ans[n*m-k];
    }
};