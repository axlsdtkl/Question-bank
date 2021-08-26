class Solution {
public:
    int ans=0;
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int n=people.size();
        int l=0,r=n-1;
        for(;;){
            if(l==r){
                ans++;
                break;
            }
            if(l>r){
                break;
            }
            if(people[l]+people[r]<=limit){
                ans++;
                l++;
                r--;
                continue;
            }
            ans++;
            r--;
        }
        return ans;
    }
};