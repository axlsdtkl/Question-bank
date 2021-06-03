class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        int f[600][600]={};
        nums1.push_back(0);
        nums2.push_back(0);
        for(int i=n;i>=1;i--)nums1[i]=nums1[i-1];
        for(int i=m;i>=1;i--)nums2[i]=nums2[i-1];
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(nums1[i]==nums2[j])f[i][j]=f[i-1][j-1]+1;
                else f[i][j]=max(f[i-1][j],f[i][j-1]);
            }
        }
        return f[n][m];
    }
};