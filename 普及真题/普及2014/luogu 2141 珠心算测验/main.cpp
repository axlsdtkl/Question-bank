#include<bits/stdc++.h>
using namespace std;
int n,a[11000],flag[11000],ans,sum[21000];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        //需要用个数组存下是否出现
    }
    //下面枚举和，枚举其中一个数，通过数组判断
    for(int j=1;j<=n;j++)
        for(int l=1;l<=n;l++){
            if(j!=l) sum[a[j]+a[l]]=1;
            }
    for(int i=1;i<=n;i++)
        if(sum[a[i]]==1)ans++;
    cout<<ans<<endl;
    return 0;
}
