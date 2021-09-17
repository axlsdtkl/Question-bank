class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l=-1,r=nums.size()-1;
        while(l+1<r){
            int mid=(l+r)>>1;
            if(nums[mid+1]-nums[mid]>0)l=mid;
            else r=mid;
        }
        return r;
    }
};