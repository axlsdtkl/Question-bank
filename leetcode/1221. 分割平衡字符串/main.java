class Solution {
    public int balancedStringSplit(String s) {
        int n=s.length();
        int sum=0,ans=0;
        for(int i=0;i<n;i++){
            if(s.charAt(i)=='L')sum++;
            else sum--;
            if(sum==0)ans++;
        }
        return ans;
    }
}