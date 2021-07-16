#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
struct data{
    int type,x,y,res;
}a[N];
char s[N];
int len,n,ques,num[N],t,cnt,top,m,q[N],flag[N];
int read(int i){
    int res=0;
    while(s[i]>='0'&&s[i]<='9')res=res*10+s[i]-'0',i++;
    return res;
}
void work(int now){
    if(a[now].type==-1){
        flag[a[now].x]=1;
        return;
    }
    if(a[now].type!=a[a[now].x].res)work(a[now].y);
    if(a[now].type!=a[a[now].y].res)work(a[now].x);
}
int main(){
    gets(s);
    len=strlen(s);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>num[i];
    for(int i=0;i<len;i++){
        if(s[i]=='x'){
            int x=read(i+1);
            cnt++;
            a[cnt].type=-1;
            a[cnt].x=x;
            a[cnt].res=num[x];
            top++;
            q[top]=cnt;
        }else if(s[i]=='&'){
            cnt++;
            a[cnt].type=0;
            a[cnt].x=q[top-1];
            a[cnt].y=q[top];
            a[cnt].res=a[a[cnt].x].res&a[a[cnt].y].res;
            top--;
            q[top]=cnt;
        }else if(s[i]=='|'){
            cnt++;
            a[cnt].type=1;
            a[cnt].x=q[top-1];
            a[cnt].y=q[top];
            a[cnt].res=a[a[cnt].x].res|a[a[cnt].y].res;
            top--;
            q[top]=cnt;
        }else if(s[i]=='!')a[cnt].res^=1;
    }
    int ans=a[cnt].res;
    work(cnt);
    cin>>t;
    while(t--){
        cin>>ques;
        if(flag[ques])cout<<1-ans<<endl;
        else cout<<ans<<endl;
    }
    return 0;
}
