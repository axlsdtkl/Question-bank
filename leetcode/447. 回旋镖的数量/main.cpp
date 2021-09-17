class Solution {
public:
    int sqr(int x){
        return x*x;
    }
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int ans=0;
        int n=points.size();
        map<int,int>M;
        for(int i=0;i<n;i++){
            M.clear();
            for(int j=0;j<n;j++){
                int d1=sqr(points[i][0]-points[j][0])+sqr(points[i][1]-points[j][1]);
                M[d1]++;
            }
            for(auto x:M){
                int y=x.second;
                ans=ans+y*(y-1);
            }
        }
        return ans;
    }
};