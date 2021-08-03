class Solution {
public:
    vector<int>a;
    int findUnsortedSubarray(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++)a.push_back(nums[i]);
        sort(a.begin(),a.end());
        int mark1=1000000,mark2=0;
        for(int i=0;i<n;i++){
            if(a[i]!=nums[i]){
                mark1=min(mark1,i);
                mark2=max(mark2,i);
            }
        }
        if(mark1==1000000)return 0;
        return mark2-mark1+1;
    }
};
