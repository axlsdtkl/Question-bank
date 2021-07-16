#include<bits/stdc++.h>
using namespace std;
long long n,m,k,x;
int main(){
    cin>>n>>m>>k>>x;
    long long ans=1;
    long long mul=10;
    while(k){
        if(k&1)ans=ans*mul%n;
        k/=2;
        mul=mul*mul%n;
    }
    x=(x+ans*m)%n;
    cout<<x<<endl;
}
