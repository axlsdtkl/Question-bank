class Solution {
public:
    int m,ans=0;
    int flag[20];
    void dfs(int x){
        if(x>m){
            ans++;
        }
        for(int i=1;i<=m;i++){
            if(flag[i]==0){
                if(i%x==0||x%i==0){
                    flag[i]=1;
                    dfs(x+1);
                    flag[i]=0;
                }
            }
        }
    }
    int countArrangement(int n) {
        m=n;
        dfs(1);
        return ans;
    }
};