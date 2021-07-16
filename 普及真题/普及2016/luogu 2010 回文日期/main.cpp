#include<bits/stdc++.h>
int n,m,a,p;
int d[12]={31,28,31,30,31,30,31,31,30,31,30,31};
using namespace std;
int main()
{
    cin>>n>>m;
    for(int i=1;i<=12;i++)
        for(int j=1;j<=d[i-1];j++)
        {
            a=(j%10)*1000+(j/10)*100+(i%10)*10+i/10;
            int x=a*10000+i*100+j;
            if(x<n||x>m)continue;
            p++;
        }
    if(n<=92200229&&m>=92200229)p++;
    cout<<p;
}