class Solution {
    public int sumOddLengthSubarrays(int[] arr) {
        int ans=0;
        int n=arr.length;
        for(int i=0;i<n;i++){
            int le=i+1;
            int ri=n-i;
            ans=ans+arr[i]*((le+1)/2*((ri+1)/2));
            ans=ans+arr[i]*((le/2)*(ri/2));
        }
        return ans;
    }
}