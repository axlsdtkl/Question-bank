#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __int128 LL;
const int N=40000010;
const int MO=1<<30;
const int M=100005;
ll s[N],b[N];
int n,type,q[N],g[N],l[M],r[M],p[M];
ll calc(ll x){
    return 2*s[x]-s[g[x]];
}
int read(){
    int x=0;
    char ch=getchar();
    while(ch<'0'||ch>'9')ch=getchar();
    while(ch>='0'&&ch<='9'){
        x=(x<<3)+(x<<1)+ch-'0';
        ch=getchar();
    }
    return x;
}
void write(LL x){
    if(x>9)write(x/10);
    putchar(x%10+'0');
}
int main(){
    n=read();
    type=read();
    if(type==0){
        for(int i=1;i<=n;i++)s[i]=s[i-1]+read();
    }else{
        int x=read(),y=read(),z=read(),m,now=1;
        b[1]=read();
        b[2]=read();
        m=read();
        for(int i=1;i<=m;i++){
            p[i]=read();
            l[i]=read();
            r[i]=read();
        }
        for(int i=3;i<=n;i++){
            b[i]=(x*b[i-1]+y*b[i-2]+z)%MO;
        }
        for(int i=1;i<=n;i++){
            if(i>p[now])now++;
            s[i]=s[i-1]+(b[i]%(r[now]-l[now]+1))+l[now];
        }
    }
    int head=1,tail=1;
    for(int i=1;i<=n;i++){
        while(head<tail&&calc(q[head+1])<=s[i])head++;
        g[i]=q[head];
        while(head<tail&&calc(q[tail])>=calc(i))tail--;
        q[++tail]=i;
    }
    int now=n;LL ans=0;
    while(now)ans+=((LL)s[now]-s[g[now]])*(s[now]-s[g[now]]),now=g[now];
    write(ans);
    cout<<endl;
    return 0;
}
