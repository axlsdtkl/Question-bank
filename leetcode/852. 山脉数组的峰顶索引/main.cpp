class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n=arr.size();
        int f[11000]={};
        int g[11000]={};
        if(arr[1]>arr[0])f[1]=1;
        for(int i=2;i<n;i++)
            if(f[i-1]&&arr[i]>arr[i-1])f[i]=1;
        if(arr[n-2]>arr[n-1])g[n-2]=1;
        for(int i=n-3;i>=0;i--)
            if(g[i+1]&&arr[i]>arr[i+1])g[i]=1;
        for(int i=1;i<n-1;i++){
            if(f[i]&&g[i])return i;
        }
        return 0;
    }
};