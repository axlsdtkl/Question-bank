class Solution {
public:
    int f[60];
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        int n=ranges.size();
        for(int i=0;i<n;i++){
            int x=ranges[i][0];
            int y=ranges[i][1];
            f[x]++;
            f[y+1]--;
        }
        for(int i=1;i<=50;i++)f[i]=f[i-1]+f[i];
        for(int i=left;i<=right;i++){
            if(f[i]==0)return false;
        }
        return true;
    }
};