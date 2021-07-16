#include<bits/stdc++.h>
using namespace std;
const int MO=10007;
const int N=110000;
int n,top;
char s[N],st[N],ans[N];
int cnt,cnt1,one[N],zero[N];
int main(){
    cin>>n;
    cin>>(s+1);
    cnt=1;
    ans[cnt]='.';
    for(int i=1;i<=n;i++){
        if(s[i]=='('){
            cnt1++;
            st[cnt1]=s[i];
        }else if(s[i]=='+'){
            if(st[cnt1]=='+'||st[cnt1]=='*'){
                ans[++cnt]=st[cnt1--];
            }
            st[++cnt1]=s[i];
        }else if(s[i]=='*'){
            if(st[cnt1]=='*'){
                ans[++cnt]=st[cnt1--];
            }
            st[++cnt1]=s[i];
        }else if(s[i]==')'){
            while(st[cnt1]!='('){
                ans[++cnt]=st[cnt1--];
            }
            cnt1--;
        }
        if(s[i]=='*'||s[i]=='+')ans[++cnt]='.';
    }
    while(cnt1>0){
        ans[++cnt]=st[cnt1--];
    }
    top=0;
    for(int i=1;i<=cnt;i++){
        if(ans[i]=='.')top++,one[top]=zero[top]=1;
        else if(ans[i]=='+'){
            top--;
            one[top]=(one[top]*zero[top+1]+one[top+1]*zero[top]+one[top]*one[top+1])%MO;
            zero[top]=(zero[top]*zero[top+1])%MO;
        }else{
            top--;
            zero[top]=(zero[top]*one[top+1]+one[top]*zero[top+1]+zero[top]*zero[top+1])%MO;
            one[top]=(one[top]*one[top+1])%MO;
        }
    }
    cout<<zero[1]<<endl;
}
