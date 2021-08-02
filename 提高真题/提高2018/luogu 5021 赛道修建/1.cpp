#include<bits/stdc++.h>
using namespace std;
const int N=51000;
struct edge{
    int o,l;
};
vector<edge>e[N];
int n,m,x,y,z,l,r,mid,dp[N],q[N],res;
bool flag[N];
void dfs(int now,int fa,int mid){
    int s=e[now].size();
    for(int i=0;i<s;i++){
        edge p=e[now][i];
        if(p.o==fa)continue;
        dfs(p.o,now,mid);
    }
    int cnt=0;
    for(int i=0;i<s;i++){
        edge p=e[now][i];
        if(p.o!=fa){
            cnt++;
            q[cnt]=dp[p.o]+p.l;
        }
    }
    sort(q+1,q+cnt+1);
    for(int i=1;i<=cnt;i++)flag[i]=0;
    for(int i=1;i<=cnt;i++)if(q[i]>=mid)res--,flag[i]=1;
    int r=1;
    for(int i=1;i<=cnt;i++){
        if(flag[i]==0){
            int l=i;
            int r=cnt+1;
            while(l+1<r){
                int mi=(l+r)/2;
                if(q[i]+q[mi]<mid)l=mi;
                else r=mi;
            }
            while(flag[r]==1&&r<cnt)r++;
            if(r<=cnt&&flag[r]==0){
                flag[r]=flag[i]=1;
                res--;
            }
        }
    }
    for(int i=cnt;i>=1;i--){
        if(flag[i]==0){
            dp[now]=q[i];
            break;
        }
    }
}
int check(int mid){
    res=m;
    for(int i=1;i<=n;i++)dp[i]=0;
    dfs(1,0,mid);
    if(res<=0)return 1;
    return 0;
}
int main(){
    cin>>n>>m;
    for(int i=1;i<n;i++){
        cin>>x>>y>>z;
        e[x].push_back({y,z});
        e[y].push_back({x,z});
    }
    l=0;r=1000000000;
    while(l+1<r){
        mid=(l+r)>>1;
        if(check(mid))l=mid;
        else r=mid;
    }
    cout<<l<<endl;
    return 0;
}
