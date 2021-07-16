#include<bits/stdc++.h>
using namespace std;
char s1[200],s2[2000];
int now,f[200][200];
int len1,len2,mark;
int main(){
    for(int i='A';i<='Z';i++){
        now=i;
        for(int j='A';j<='Z';j++){
            f[now][j]=i;
            now++;
            if(now>'Z')now='A';
        }
    }
    cin>>(s1+1);
    len1=strlen(s1+1);
    for(int i=1;i<=len1;i++){
        if(s1[i]>='a'&&s1[i]<='z')s1[i]+='A'-'a';
    }
    cin>>(s2+1);
    len2=strlen(s2+1);
    int p=1;
    for(int i=1;i<=len2;i++){
        if(s2[i]>='a'&&s2[i]<='z')mark=1,s2[i]+='A'-'a';
        else mark=0;
        s2[i]=f[s2[i]][s1[p]];
        p=p%len1+1;
        if(mark)s2[i]+='a'-'A';
    }
    cout<<(s2+1)<<endl;
    return 0;
}
