#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    const static int N=11000;
    int numCnt=0,bCnt=0,teCnt=0;
    char b[N],c[N];
    int a[N];
    string decodeString(string s) {
        int n=s.length();
        for(int i=0;i<n;i++){
            if(s[i]>='0'&&s[i]<='9'){
                if(i>0&&s[i-1]>='0'&&s[i-1]<='9'){
                    a[numCnt]=a[numCnt]*10+s[i]-'0';
                }else numCnt++,a[numCnt]=s[i]-'0';
            }else{
                if(s[i]!=']')bCnt++,b[bCnt]=s[i];
                else{
                    teCnt=0;
                    while(b[bCnt]!='['){
                        teCnt++;
                        c[teCnt]=b[bCnt];
                        bCnt--;
                    }
   
                    bCnt--;
                    for(int k=1;k<=a[numCnt];k++){
                        for(int j=teCnt;j>=1;j--){
                            bCnt++;
                            b[bCnt]=c[j];
                        }
                    }
                    numCnt--;
                }
            }
        }
        string res="";
        for(int i=1;i<=bCnt;i++)res+=b[i];
        return res;
    }
};
