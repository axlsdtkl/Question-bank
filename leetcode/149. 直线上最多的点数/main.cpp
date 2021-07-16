class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n=points.size();
        int res=0;
        if(n<2)return n;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int ans=2;
                int x=points[j][0]-points[i][0];
                int y=points[j][1]-points[i][1];
                for(int k=j+1;k<n;k++){
                    int xx=points[k][0]-points[i][0];
                    int yy=points[k][1]-points[i][1];
                    if(x*yy==y*xx)ans++;
                }
                res=max(res,ans);
            }
        }
        return res;
    }
};