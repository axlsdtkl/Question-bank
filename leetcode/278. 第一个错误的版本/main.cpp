// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long long l=0,r=(long long)n+1;
        while(l+1<r){
            long long mid=(l+r)>>1;
            if(isBadVersion(mid))r=mid;
            else l=mid;
        }
        return r;
    }
};