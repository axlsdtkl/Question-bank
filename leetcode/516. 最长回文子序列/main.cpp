class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n=s.length();
        int f[1100][1100];
        int ans=1;
        for(int i=0;i<n;i++)f[i][i]=1;
        for(int i=2;i<=n;i++){
            for(int j=0;j<=n-i;j++){
                int k=j+i-1;
                if(s[j]!=s[k])f[j][k]=max(f[j+1][k],f[j][k-1]);
                else f[j][k]=f[j+1][k-1]+2;
                ans=max(ans,f[j][k]);
            }
        }
        return ans;
    }
};