#include<bits/stdc++.h>
using namespace std;
char s[10];
int ans,len;
int main(){
    cin>>s;
    len=strlen(s);
    for(int i=0;i<len;i++){
        if(s[i]=='1')ans++;
    }
    cout<<ans<<endl;
    return 0;
}
