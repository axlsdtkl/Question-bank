class Solution {
public:
    struct arr{
        int p,c;
    }a[110000];
    static bool cmp(arr a,arr b){
        return a.c<b.c;
    }
    priority_queue<int>q;
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n=profits.size();
        for(int i=0;i<n;i++){
            a[i+1].p=profits[i];
            a[i+1].c=capital[i];
        }
        sort(a+1,a+n+1,cmp);
        int l=1;
        for(int i=1;i<=k;i++){
            while(l<=n&&a[l].c<=w){
                q.push(a[l].p);
                l++;
            }
            if(q.size()>0){
                w+=q.top();
                q.pop();
            }
        }
        return w;
    }
};