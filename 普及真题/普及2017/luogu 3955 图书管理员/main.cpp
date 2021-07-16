#include<bits/stdc++.h>
using namespace std;
int n,q,a[111000],x,y;
bool flag;
int c(int x)
{
    int s=1;
    while(x){s*=10;x--;}
    return s;
}
int main(){
    cin>>n>>q;
    for(int i=1;i<=n;i++)cin>>a[i];
    //排序
    sort(a+1,a+n+1);
    while(q--){
        cin>>x>>y;
        flag=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i]%c(x)==y)
            {
                flag=1;
                cout<<a[i]<<endl;
                break;
            }
        }
        if(flag==0)cout<<"-1\n";
        
    }
    return 0;
}
