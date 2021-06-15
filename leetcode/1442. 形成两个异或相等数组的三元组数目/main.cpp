class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n=arr.size();
        int a[400]={};
        for(int i=0;i<n;i++)a[i+1]=arr[i];
        for(int i=1;i<=n;i++)a[i]=a[i-1]^a[i];
        int ans=0;
        for(int i=1;i<=n-1;i++){
            for(int j=i+1;j<=n;j++){
                for(int k=j;k<=n;k++){
                    if(a[j-1]^a[i-1]==a[k]^a[j-1])ans++;
                }
            }
        }
        return ans;
    }
};