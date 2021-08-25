class Solution {
public:
    struct node{
        int s,id;
        bool operator<(const node &up)const{
            return s>up.s;
        }
    };
    priority_queue<node>q;
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int m=primes.size();
        q.push({1,0});
        for(int i=1;i<n;i++){
            node x=q.top();
            q.pop();
            for(int j=x.id;j<m;j++){
                if((long long)x.s*primes[j]<=2147483647)
                    q.push({x.s*primes[j],j});
            }
        }
        return q.top().s;
    }
};