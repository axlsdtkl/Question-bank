class Solution {
public:
    string largestNumber(vector<int>& cost, int target) {
        int len[6000]={};
        string f[6000];
        memset(len,-42,sizeof(len));
        len[0]=0;
        f[0]="";
        int c[10]={};
        for(int i=0;i<9;i++)c[i+1]=cost[i];
        for(int i=1;i<=target;i++){
            for(int j=1;j<=9;j++){
                if(i>=c[j]&&len[i-c[j]]>=0){
                    if(len[i-c[j]]+1>len[i]){
                        len[i]=len[i-c[j]]+1;
                        f[i]=f[i-c[j]]+char(j+'0');
                    }else if(len[i-c[j]]+1==len[i]){
                        string s=f[i-c[j]]+char(j+'0');
                        if(s>f[i])f[i]=s;
                    }
                }
            }
        }
        if(len[target]<0)return "0";
        return f[target];
    }
};