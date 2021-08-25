class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int ans=0;
        int cnt;
        int n=nums.size();
        map<long long,int>f[1100];
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                long long d=(long long)nums[i]-nums[j];
                if(f[j].count(d)==0)cnt=0;
                else cnt=f[j][d];
                ans+=cnt;
                f[i][d]+=cnt+1;
            }
        }
        return ans;
    }
};