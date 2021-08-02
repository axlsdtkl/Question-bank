#include<bits/stdc++.h>
using namespace std;
int a,b,c,d,ans=10000,x,y;
int month[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int main(){
    scanf("%d-%d",&x,&y);
    a=x/10;
    b=x%10;
    c=y/10;
    d=y%10;
    for(int i=1;i<=12;i++){
        for(int j=1;j<=month[i];j++){
            int sum=0;
            if(i/10!=a)sum++;
            if(i%10!=b)sum++;
            if(j/10!=c)sum++;
            if(j%10!=d)sum++;
            ans=min(ans,sum);
        }
    }
    cout<<ans<<endl;
    return 0;
}
