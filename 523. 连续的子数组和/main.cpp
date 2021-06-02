class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int sum[110000]={};
        for(int i=0;i<n;i++)sum[i+1]=sum[i]+nums[i];
        for(int i=1;i<=n;i++)sum[i]%=k;
        map<int,int>mp;
        mp[0]=0;
        for(int i=1;i<=n;i++){
            if(mp.count(sum[i])>0){
                int prePosition=mp[sum[i]];
                if(i-prePosition>=2)return true;
            }else mp[sum[i]]=i;
        }
        return false;
    }
};