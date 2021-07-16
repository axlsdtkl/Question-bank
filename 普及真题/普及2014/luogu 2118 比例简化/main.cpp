#include<bits/stdc++.h>
using namespace std;
int a,b,l,m=9999999,x=1000000000,y=1;
int gcd(int c,int d){
    //碾转相除法
//    while(c)
//    {
//        d=c/d;
//
//    }
    if(d==0)return c;
    return gcd(d,c%d);//logn
}
int main(){
    cin>>a>>b>>l;
    for(int i=1;i<=l;i++)
    {
        for(int j=1;j<=l;j++)
        {
            if(1.0*i/j>=1.0*a/b&&1.0*i/j<1.0*x/y)
            {
                x=i;
                y=j;
            }
        }
    }
    a=gcd(x,y);
    x/=a;
    y/=a;
    cout<<x<<" "<<y<<endl;
    return 0;
}
