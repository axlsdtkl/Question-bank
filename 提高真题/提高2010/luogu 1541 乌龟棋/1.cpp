#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[400],b[5],f[400][41][41][41],x;
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=m;i++){
        cin>>x;
        b[x]++;
    }
    memset(f,-42,sizeof(f));
    f[1][0][0][0]=a[1];
    for(int i=1;i<=n;i++){
        for(int j1=0;j1<=b[1];j1++){
            for(int j2=0;j2<=b[2];j2++){
                for(int j3=0;j3<=b[3];j3++){
                    int sur=(i-1)-j1-j2*2-j3*3;
                    if(sur<0)continue;
                    if(sur%4)continue;
                    int j4=sur/4;
                    int now=f[i][j1][j2][j3];
                    f[i+1][j1+1][j2][j3]=max(f[i+1][j1+1][j2][j3],now+a[i+1]);
                    f[i+2][j1][j2+1][j3]=max(f[i+2][j1][j2+1][j3],now+a[i+2]);
                    f[i+3][j1][j2][j3+1]=max(f[i+3][j1][j2][j3+1],now+a[i+3]);
                    f[i+4][j1][j2][j3]=max(f[i+4][j1][j2][j3],now+a[i+4]);
                }
            }
        }
    }
    cout<<f[n][b[1]][b[2]][b[3]]<<endl;
    return 0;
}
