class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int ans=0,l,r;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                l=j;
                r=n;
                while(l+1<r){
                    int mid=(l+r)>>1;
                    if(nums[i]+nums[j]<=nums[mid])r=mid;
                    else l=mid;
                }
                ans+=(r-j-1);
            }
        }
        return ans;
    }
};