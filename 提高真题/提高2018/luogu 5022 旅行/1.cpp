#include<bits/stdc++.h>
using namespace std;
const int N=500010;
int n,m,vis[N],ans[N],cnt,f[N],rings[N],flag,tmp,temp,head[N],ver[N<<1],nex[N<<1],tot;
int u,v;
struct Node{
    int x,y;
}node[N<<1];
void add(int x,int y){
    ver[++tot]=y;
    nex[tot]=head[x];
    head[x]=tot;
}
bool cmp(Node a,Node b){
    return a.y>b.y;
}
void dfs(int x){
    vis[x]=1;
    ans[++cnt]=x;
    for(int i=head[x];i;i=nex[i]){
        int y=ver[i];
        if(!vis[y])dfs(y);
    }
}
void dfsRing(int x,int fa){
    if(flag)return;
    if(f[x]==0)f[x]=fa;
    else if(f[x]!=fa){
        while(fa!=x){
            rings[fa]=1;
            fa=f[fa];
        }
        rings[x]=1;
        flag=1;
        return;
    }
    for(int i=head[x];i;i=nex[i]){
        int y=ver[i];
        if(y==fa)continue;
        dfsRing(y,x);
    }
}
void sDfs(int x){
    vis[x]=1;
    ans[++cnt]=x;
    if(rings[x]){
        int flag=0;
        for(int i=head[x];i;i=nex[i]){
            if(temp)break;
            int y=ver[i];
            if(vis[y])continue;
            if(rings[y]){
                i=nex[i];
                while(vis[ver[i]])i=nex[i];
                if(i)tmp=ver[i];
                else if(y>tmp)flag=1,temp=1;
                break;
            }
        }
        for(int i=head[x];i;i=nex[i]){
            int y=ver[i];
            if(vis[y])continue;
            if(rings[y]&&flag)continue;
            sDfs(y);
        }
    }else{
        for(int i=head[x];i;i=nex[i]){
            int y=ver[i];
            if(vis[y])continue;
            sDfs(y);
        }
    }
}
int main(){
    cin>>n;
    cin>>m;
    for(int i=1;i<=m;i++){
        cin>>u>>v;
        node[i].x=u;
        node[i].y=v;
        node[i+m].x=v;
        node[i+m].y=u;
    }
    sort(node+1,node+2*m+1,cmp);
    for(int i=1;i<=2*m;i++)add(node[i].x,node[i].y);
    if(m==n-1){
        dfs(1);
        for(int i=1;i<=n;i++)printf("%d ",ans[i]);
    }else{
        dfsRing(1,1);
        flag=0;
        tmp=0x3f3f3f3f;
        sDfs(1);
        for(int i=1;i<=n;i++)printf("%d ",ans[i]);
    }
    return 0;
}
