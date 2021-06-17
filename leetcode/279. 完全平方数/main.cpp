class Solution {
public:
    int numSquares(int n) {
        int f[11000]={};
        memset(f,42,sizeof(f));
        f[0]=0;
        for(int i=1;i<=sqrt(n);i++){
            for(int j=i*i;j<=n;j++){
                f[j]=min(f[j],f[j-i*i]+1);
            }
        }
        return f[n];
    }
};