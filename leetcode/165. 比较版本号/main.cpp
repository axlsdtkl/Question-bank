class Solution {
public:
    int compareVersion(string version1, string version2) {
        int len1=version1.length();
        int len2=version2.length();
        int cnt1=0,cnt2=0,a[600]={},b[600]={};
        version1+='.';
        version2+='.';
        len1++;
        len2++;
        int x=0;
        for(int i=0;i<=len1;i++){
            if(version1[i]=='.'){
                cnt1++;
                a[cnt1]=x;
                x=0;
            }else{
                x=x*10+version1[i]-'0';
            }
        }
        x=0;
        for(int i=0;i<=len2;i++){
            if(version2[i]=='.'){
                cnt2++;
                b[cnt2]=x;
                x=0;
            }else{
                x=x*10+version2[i]-'0';
            }
        }
        for(int i=1;i<=max(cnt1,cnt2);i++){
            if(a[i]<b[i])return -1;
            if(a[i]>b[i])return 1;
        }
        return 0;
    }
};