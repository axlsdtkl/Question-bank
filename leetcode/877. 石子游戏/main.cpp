class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        int sum[600]={};
        int f[600][600]={};
        memset(f,42,sizeof(f));
        sum[0]=piles[0];
        for(int i=1;i<n;i++)sum[i]=sum[i-1]+piles[i];
        for(int i=0;i<n;i++)f[i][i]=piles[i];
        for(int i=2;i<n;i++){
            for(int j=0;j<=n-i;j++){
                int k=j+i-1;
                if(j>=1)f[j][k]=sum[k]-sum[j-1]-min(f[j+1][k],f[j][k-1]);
                else f[j][k]=sum[k]-min(f[j+1][k],f[j][k-1]);
            }
        }
        return f[0][n-1]*2>sum[n-1];
    }
};