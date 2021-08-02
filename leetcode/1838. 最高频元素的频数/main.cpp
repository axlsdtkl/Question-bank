class Solution {
public:
    long long sum[110000]={};
    int maxFrequency(vector<int>& nums, int k) {
        long long ans=0;
        sort(nums.begin(),nums.end());
        sum[0]=0;
        sum[1]=nums[0];
        for(int i=2;i<=nums.size();i++)sum[i]=sum[i-1]+nums[i-1];
        long long l=1;
        for(int i=1;i<=nums.size();i++){
            while((i-l+1)*nums[i-1]-(sum[i]-sum[l-1])>k)l++;
            ans=max(ans,i-l+1);
        }
        return ans;
    }
};