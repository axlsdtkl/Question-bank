class Solution {
public:
    static int cmp(int x,int y){
        return x>y;
    }
    int hIndex(vector<int>& citations) {
        sort(citations.begin(),citations.end(),cmp);
        int res=0;
        for(int i=0;i<citations.size();i++){
            if(citations[i]>=(i+1))res=i+1;
        }
        return res;
    }
};