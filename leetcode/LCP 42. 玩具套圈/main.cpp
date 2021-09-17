class Solution {
public:
    int circleGame(vector<vector<int>>& toys, vector<vector<int>>& circles, int r) {
        int n=toys.size(),m=circles.size();
        set<pair<int,int>>S;
        for(int i=0;i<m;i++){
            S.insert({circles[i][0],circles[i][1]});
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(toys[i][2]>r)continue;
            int ok=0;
            for(int j=-r;!ok&&j<=r;j++){
                for(int k=-r;!ok&&k<=r;k++){
                    if(j*j+k*k<=(r-toys[i][2])*(r-toys[i][2])){
                        if(S.count({toys[i][0]+j,toys[i][1]+k})==1){
                            ans++;
                            ok=1;
                        }
                    }
                }
            }
        }
        return ans;
    }
};