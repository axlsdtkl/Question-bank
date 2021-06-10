class Solution {
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        int m=group.size();
        int f[110][110][110]={};
        f[0][0][0]=1;
        for(int i=0;i<m;i++){
            for(int j=0;j<=n;j++)
                for(int k=0;k<=minProfit;k++)
                    f[i+1][j][k]=f[i][j][k];
            for(int j=0;j<=n-group[i];j++){
                for(int k=0;k<=minProfit;k++){
                    f[i+1][j+group[i]][min(minProfit,k+profit[i])]+=f[i][j][k];
                    f[i+1][j+group[i]][min(minProfit,k+profit[i])]%=1000000007;
                }
            }
        }
        int res=0;
        for(int i=0;i<=n;i++){
            res=(res+f[m][i][minProfit])%1000000007;
        }
        return res;
    }
};