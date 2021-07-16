#include<bits/stdc++.h>
using namespace std;
long long n,m,k,x,y,d,z,ans=-1000,cnt;
long long a[130][130];
int main(){
    cin>>d;
    cin>>n;
    while(n--){
        cin>>x>>y>>z;
        x++;
        y++;
        a[x][y]+=z;
    }
    for(int i=1;i<=129;i++){
        for(int j=1;j<=129;j++){
            a[i][j]=a[i-1][j]+a[i][j-1]-a[i-1][j-1]+a[i][j];
        }
    }
    for(int i=1;i<=129;i++){
        for(int j=1;j<=129;j++){
            int xx=i+d,yy=j+d;
            int x=i-d,y=j-d;
            xx=min(xx,129);
            yy=min(yy,129);
            x=max(1,x);
            y=max(1,y);
            int sum=a[xx][yy]-a[xx][y-1]-a[x-1][yy]+a[x-1][y-1];
            if(sum>ans)ans=sum,cnt=1;
            else if(sum==ans)cnt++;
        }
    }
    cout<<cnt<<" "<<ans<<endl;
    return 0;
}
