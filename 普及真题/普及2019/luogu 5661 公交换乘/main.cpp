#include<bits/stdc++.h>
using namespace std;
long long t,n,m;
long long a[110][110],f[10020];
int main(){
    cin>>t>>n>>m;
    for(int i=1;i<=t;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    for(int i=1;i<t;i++)
    {
        memset(f,0,sizeof(f));
        for(int j=1;j<=n;j++)
        {
            if(a[i][j]>a[i+1][j])continue;
            for(int z=a[i][j];z<=m;z++)
            {
                int v=a[i][j];
                int w=a[i+1][j]-a[i][j];
                f[z]=max(f[z],f[z-v]+w);
            }
        }
        m+=f[m];
    }
    cout<<m<<endl;
}
