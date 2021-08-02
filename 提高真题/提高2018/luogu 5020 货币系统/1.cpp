#include<bits/stdc++.h>
using namespace std;
const int N=110;
const int M=26000;
int a[N];
int f[M];
int T,n,ans;
int main(){
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i];
        sort(a+1,a+n+1);
        memset(f,0,sizeof(f));
        f[0]=1;
        ans=n;
        for(int i=1;i<=n;i++){
            if(f[a[i]]){
                ans--;
                continue;
            }
            for(int j=a[i];j<=a[n];j++){
                if(f[j-a[i]])f[j]=1;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
