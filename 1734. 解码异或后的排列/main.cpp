class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        int sum=0;
        int n=encoded.size();
        for(int i=1;i<=(n+1);i++)sum^=i;
        for(int i=0;i<n;i++){
            if(i%2==1)sum^=encoded[i];
        }
        vector<int>ans;
        ans.push_back(sum);
        for(int i=1;i<=n;i++)ans.push_back(ans[i-1]^encoded[i-1]);
        return ans;
    }
};