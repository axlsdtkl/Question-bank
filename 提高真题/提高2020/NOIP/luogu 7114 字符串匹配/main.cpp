#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=(1<<20)+5;
char str[N];
int T,n,pr;
int kmp[N],tms[30],suf[N],pre[N],per[30];
ll ans;
void work(){
    char c=getchar();
    ans=0;
    memset(kmp,0,sizeof(kmp));
    memset(tms,0,sizeof(tms));
    memset(suf,0,sizeof(suf));
    memset(pre,0,sizeof(pre));
    memset(per,0,sizeof(per));
    while(c>'z'||c<'a')c=getchar();
    n=0;
    while(c<='z'&&c>='a')str[++n]=c,c=getchar();
    pr=0;
    for(int i=2;i<=n;i++){
        while(pr!=0&&str[i]!=str[pr+1])pr=kmp[pr];
        if(str[i]==str[pr+1])pr++;
        kmp[i]=pr;
    }
    int cnt=0;
    for(register int i=1;i<=26;i++)tms[i]=0;
    for(register int i=n;i>=1;i--){
        tms[str[i]-'a'+1]++;
        if(tms[str[i]-'a'+1]&1)
            suf[i]=suf[i+1]+1;
        else suf[i]=suf[i+1]-1;
    }
    for(register int i=1;i<=26;i++)tms[i]=0;
    for(register int i=1;i<=n;i++){
        tms[str[i]-'a'+1]++;
        if(tms[str[i]-'a'+1]&1)
            pre[i]=pre[i-1]+1;
        else pre[i]=pre[i-1]-1;
    }
    for(register int i=1;i<n;i++){
        if(i>=2){
            ans+=per[suf[i+1]];
            for(register int j=i+i;j<n;j+=i){
                if(((i%(j-kmp[j]))==0)&&((j/(j-kmp[j]))>1))
                    ans+=(per[suf[j+1]]);
                else break;
            }
        }
        for(register int j=1;j<pre[i];j++)per[j]=per[j];
        for(register int j=pre[i];j<=26;j++)per[j]=per[j]+1;
    }
    cout<<ans<<endl;
}
int main(){
    scanf("%d",&T);
    while(T--){
        work();
    }
    return 0;
}
