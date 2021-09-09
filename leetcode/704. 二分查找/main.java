class Solution {
    public int search(int[] nums, int target) {
        int n=nums.length;
        int l=-1,r=n;
        while(l+1<r){
            int mid=(l+r)>>1;
            if(nums[mid]<=target)l=mid;
            else r=mid;
        }
        if(l==-1)return -1;
        if(nums[l]==target)return l;
        else return -1;
    }
}