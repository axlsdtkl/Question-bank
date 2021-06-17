/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return       -1 if num is lower than the guess number
 *                1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        long long l=0,r=(long long)n+1;
        while(l+1<r){
            long long mid=(l+r)>>1;
            int res=guess(mid);
            if(res==-1)r=mid;
            if(res==1)l=mid;
            if(res==0)return mid;
        }
        return l;
    }
};