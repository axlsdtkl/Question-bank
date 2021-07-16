#include<bits/stdc++.h>
using namespace std;
const int N=600;
int n,m,a[N],f[N][410],ans;
void Min(int &x,int y){
    if(y<x)x=y;
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    memset(f,42,sizeof(f));
    for(int j=0;j<2*m;j++){
        f[1][j]=j;
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<2*m;j++){
            if(a[i]+j>=a[i+1])Min(f[i+1][a[i]+j-a[i+1]],f[i][j]+a[i]+j-a[i+1]);
            else if(a[i]+j+m<=a[i+1]){
                for(int k=0;k<2*m;k++)Min(f[i+1][k],f[i][j]+k);
            }else for(int k=0;k<m;k++)
                Min(f[i+1][a[i]+j+k+m-a[i+1]],f[i][j]+a[i]+j+k+m-a[i+1]);
        }
    }
    ans=1<<30;
    for(int i=0;i<2*m;i++)Min(ans,f[n][i]);
    cout<<ans<<endl;
    return 0;
}
