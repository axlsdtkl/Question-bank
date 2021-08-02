#include<bits/stdc++.h>
using namespace std;
int n,a[100001];
int d=0;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=2;i<=n;i++){
        if(a[i]>a[i-1]){
            d=d+a[i]-a[i-1];
        }
    }
    cout<<(d+a[1]);
    return 0;
}