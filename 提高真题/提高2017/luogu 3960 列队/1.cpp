#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=300010;
struct sl{
    int x,y,id;
    bool flag;
};
vector<ll>v[MAXN];
vector<int>a;
int n,m,q,len,len2,st,ed;
sl g[MAXN];
ll p[2*MAXN];
int bit1[2*MAXN],bit2[2*MAXN];
int lowbit(int x){
    return x&(-x);
}
void add(int x,int y,int *bit){
    while(x<=600010){
        bit[x]+=y;x+=lowbit(x);
    }
}
int getsum(int x,int *bit){
    int re=0;
    while(x>0){
        re+=bit[x];x-=lowbit(x);
    }
    return re;
}
bool cmp1(sl x,sl y){
    if(x.x!=y.x)return x.x<y.x;
    else return x.id<y.id;
}
bool cmp2(sl x,sl y){
    return x.id<y.id;
}
int main(){
    scanf("%d%d%d",&n,&m,&q);len=n;
    for(int i=1;i<=q;i++){
        scanf("%d%d",&g[i].x,&g[i].y);
        g[i].id=i;g[i].flag=false;
    }
    for(int i=1;i<=n;i++)p[i]=1ll*i*m;
    for(int i=1;i<=600010;i++){
        bit1[i]=bit2[i]=lowbit(i);
    }
    sort(g+1,g+1+q,cmp1);
    st=1;
    ed=1;
    while(st<=q){
        while(ed<q&&g[st].x==g[ed+1].x)++ed;
        a.clear();len2=m;
        for(int i=st;i<=ed;i++){
            if(g[i].y==m){
                g[i].flag=true;continue;
            }
            int l=1,r=len2;
            while(l<r){
                int mid=(l+r)>>1;
                if(getsum(mid,bit2)>=g[i].y)r=mid;
                else l=mid+1;
            }
            add(l,-1,bit2);a.push_back(l);g[i].y=l;++len2;
        }
        for(int i=0;i<a.size();i++)add(a[i],1,bit2);
        st=ed+1;
    }
    sort(g+1,g+1+q,cmp2);
    for(int i=1;i<=q;i++){
        ll ans;
        if(!g[i].flag){
            if(g[i].y<m){
                ans=1ll*(g[i].x-1)*m+g[i].y;
                printf("%lld\n",ans);
            }else{
                g[i].y=g[i].y-m;
                ans=v[g[i].x][g[i].y];
                printf("%lld\n",ans);
            }
        }
        int l=1,r=len;
        while(l<r){
            int mid=(l+r)>>1;
            if(getsum(mid,bit1)>=g[i].x)r=mid;
            else l=mid+1;
        }
        add(l,-1,bit1);
        if(!g[i].flag)v[g[i].x].push_back(p[l]);
        else{
            ans=p[l];
            printf("%lld\n",ans);
        }
        p[++len]=ans;
    }
    return 0;
}
