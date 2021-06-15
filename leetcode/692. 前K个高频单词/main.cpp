class Solution {
public:
    struct data{
        string s;
        int cnt;
    }a[11000];
    static bool cmp(data a,data b){
        if(a.cnt>b.cnt)return 1;
        if(a.cnt<b.cnt)return 0;
        return a.s<b.s;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int>ma;
        int n=words.size();
        for(int i=0;i<n;i++)ma[words[i]]++;
        int m=0;
        for(auto [s,cnt]:ma){
            m++;
            a[m].s=s;
            a[m].cnt=cnt;
        }
        sort(a+1,a+m+1,cmp);
        vector<string>ans;
        for(int i=1;i<=k;i++)ans.push_back(a[i].s);
        return ans;
    }
};