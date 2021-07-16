#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
    cin>>n;
    for(int i=2;i<=n-1;i++){
        if(n%i==0){
            cout<<n/i<<endl;
            return 0;
        }
    }
//    for(int i=n-1;i>=2;i--){
//        if(n%i==0){
//            cout<<i<<endl;
//            return 0;
//        }
//    }
}
