class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        int f[6000]={};
        f[0]=1;
        for(int i=0;i<n;i++){
            for(int j=coins[i];j<=amount;j++){
                f[j]+=f[j-coins[i]];
            }
        }
        return f[amount];
    }
};