class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        int n=dictionary.size();
        int len=s.length();
        int mark=-1,ans=0;
        for(int i=0;i<n;i++){
            int len1=dictionary[i].length();
            int nowIndex=0;
            int flag=1;
            for(int j=0;j<len1;j++){
                while(nowIndex<len&&s[nowIndex]!=dictionary[i][j])nowIndex++;
                if(nowIndex==len){
                    flag=0;
                    break;
                }
                nowIndex++;
            }
            if(flag==1){
                if(len1>ans){
                    ans=len1;
                    mark=i;
                }else if(len1==ans){
                    if(dictionary[i]<dictionary[mark])mark=i;
                }
            }
        }
        if(mark==-1)return "";
        return dictionary[mark];
    }
};