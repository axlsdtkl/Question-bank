class Solution {
public:
    map<int,int>ma;
    int f[110000]={};
    int minOperations(vector<int>& target, vector<int>& arr) {
        int n=target.size();
        int m=arr.size();
        for(int i=0;i<n;i++){
            ma[target[i]]=i+1;
        }
        int ans=0;
        for(int i=0;i<m;i++){
            if(ma.count(arr[i])==0)continue;
            int pos=ma[arr[i]];
            int l=0,r=ans+1;
            while(l+1<r){
                int mid=(l+r)>>1;
                if(f[mid]<pos)l=mid;
                else r=mid;
            }
            f[r]=pos;
            if(r>ans)ans=r;
        }
        return n-ans;
    }
};