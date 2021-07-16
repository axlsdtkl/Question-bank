#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
    cin>>n;
    if(n%2==1){
        cout<<-1<<endl;
        return 0;
    }
    for(int i=30;i>=1;i--){
        if(n>=(1<<i)){
            cout<<(1<<i)<<" ";
            n-=(1<<i);
        }
    }
    return 0;
}
