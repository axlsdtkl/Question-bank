class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n=arr.size();
        int a[40000]={};
        a[1]=arr[0];
        for(int i=1;i<n;i++)a[i+1]=a[i]^arr[i];
        int m=queries.size();
        vector<int>ans;
        for(int i=0;i<m;i++){
            int l=queries[i][0];
            l++;
            int r=queries[i][1];
            r++;
            ans.push_back(a[r]^a[l-1]);
        }
        return ans;
    }
};