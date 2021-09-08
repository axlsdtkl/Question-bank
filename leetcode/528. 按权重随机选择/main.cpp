class Solution {
public:
    vector<int>arr;
    int sum;
    Solution(vector<int>& w) {
        int n=w.size();
        arr.resize(n);
        arr[0]=w[0];
        for(int i=1;i<n;i++)arr[i]=arr[i-1]+w[i];
        sum=arr[n-1];
    }
    
    int pickIndex() {
        int x=rand()%sum+1;
        int id=lower_bound(arr.begin(),arr.end(),x)-arr.begin();
        return id;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
