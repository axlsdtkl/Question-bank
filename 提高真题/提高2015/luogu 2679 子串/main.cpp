#include<bits/stdc++.h>
using namespace std;
const int mo=1000000007;
int n,m,p,ans[2][210][210],res[2][210][210];
char s1[1100],s2[1100];
int main(){
    cin>>n>>m>>p;
    cin>>(s1+1);
    cin>>(s2+1);
    ans[0][0][0]=1;
    for(int i=1;i<=n;i++){
        int now=i%2;
        ans[now][0][0]=1;
        for(int j=1;j<=m;j++){
            for(int k=1;k<=p;k++){
                if(s1[i]==s2[j]){
                    res[now][j][k]=(ans[1-now][j-1][k-1]+res[1-now][j-1][k])%mo;
                }else res[now][j][k]=0;
                ans[now][j][k]=(res[now][j][k]+ans[1-now][j][k])%mo;
            }
        }
    }
    cout<<ans[n%2][m][p]<<endl;
    return 0;
}
