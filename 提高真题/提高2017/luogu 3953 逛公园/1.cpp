#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int t,d[N],f[N][51],n,m,k,p;
bool working[N][51];
struct node{
    int to,len;
};
vector<node>head[N];
vector<node>h[N];
int dp(int root,int l){
    int ans=0;
    if(l<0||l>k)return 0;
    if(working[root][l]){
        working[root][l]=false;
        return -1;
    }
    if(f[root][l]!=-1)return f[root][l];
    working[root][l]=true;
    for(int i=0;i<h[root].size();i++){
        node e=h[root][i];
        int val=dp(e.to,d[root]+l-d[e.to]-e.len);
        if(val==-1){
            working[root][l]=false;
            return -1;
        }
        ans=(ans+val)%p;
    }
    working[root][l]=false;
    if(root==1&&l==0)ans++;
    f[root][l]=ans;
    return ans;
}
int work(){
    cin>>n>>m>>k>>p;
    for(int i=1;i<=n;i++)head[i].clear(),h[i].clear();
    int a,b,c;
    for(int i=1;i<=m;i++){
        cin>>a>>b>>c;
        node e;
        e.to=b;e.len=c;
        head[a].push_back(e);
        e.to=a;
        h[b].push_back(e);
    }
    memset(d,0x3f,sizeof(d));
    memset(f,-1,sizeof(f));
    queue<int>q;
    q.push(1);d[1]=0;
    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(int i=0;i<head[x].size();i++){
            if(d[head[x][i].to]>d[x]+head[x][i].len){
                d[head[x][i].to]=d[x]+head[x][i].len;
                q.push(head[x][i].to);
            }
        }
    }
    int ans=0;
    for(int i=0;i<=k;i++){
        int val=dp(n,i);
        if(val==-1)return -1;
        ans=(ans+val)%p;
    }
    return ans;
}
int main(){
    cin>>t;
    while(t--)cout<<work()<<endl;
    memset(d,0x3f,sizeof(d));
    return 0;
}
