class Solution {
public:
    int nums[110]={};
    int getMaximumGenerated(int n) {
        nums[0]=0;
        nums[1]=1;
        for(int i=2;i<=n;i++){
            if(i%2==0)nums[i]=nums[i>>1];
            else nums[i]=nums[i/2]+nums[i/2+1];
        }
        int res=0;
        for(int i=0;i<=n;i++)res=max(res,nums[i]);
        return res;
    }
};