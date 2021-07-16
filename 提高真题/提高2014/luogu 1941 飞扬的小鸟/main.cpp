#include<bits/stdc++.h>
using namespace std;
const int N=10005;
int n,m,k,a[N],b[N],x,y,z,low[N],high[N],f[N][2100],ans,flag[N];
int main(){
    cin>>n>>m>>k;
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i];
    }
    for(int i=1;i<=n;i++)low[i]=1,high[i]=m;
    while(k--){
        cin>>x>>y>>z;
        flag[x]=1;
        low[x]=y+1;
        high[x]=z-1;
    }
    memset(f,127,sizeof(f));
    for(int i=1;i<=m;i++)f[0][i]=0;
    for(int i=1;i<=n;i++){
        for(int j=a[i-1]+1;j<=m+a[i-1];j++){
            f[i][j]=min(f[i-1][j-a[i-1]],f[i][j-a[i-1]])+1;
        }
        for(int j=m+1;j<=m+a[i-1];j++){
            f[i][m]=min(f[i][m],f[i][j]);
        }
        for(int j=1;j<=m-b[i-1];j++){
            f[i][j]=min(f[i][j],f[i-1][j+b[i-1]]);
        }
        for(int j=1;j<low[i];j++)f[i][j]=f[0][0];
        for(int j=high[i]+1;j<=m;j++)f[i][j]=f[0][0];
    }
    ans=2147483647;
    for(int j=1;j<=m;j++){
        if(f[n][j]<=10000000)ans=min(ans,f[n][j]);
    }
    if(ans<20000000){
        cout<<1<<endl;
        cout<<ans<<endl;
        return 0;
    }
    int mark;
    for(int i=n;i>=0;i--){
        int yes=0;
        for(int j=1;j<=m;j++){
            if(f[i][j]<20000000){
                yes=1;
                break;
            }
        }
        if(yes){
            mark=i;
            break;
        }
    }
    int sum=0;
    for(int i=1;i<=mark;i++)sum+=flag[i];
    cout<<0<<endl;
    cout<<sum<<endl;
    return 0;
}
