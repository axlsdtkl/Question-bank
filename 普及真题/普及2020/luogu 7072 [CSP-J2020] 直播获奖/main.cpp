#include<bits/stdc++.h>
using namespace std;
int n,m,x,num,mark;
int score[700];
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>x;
        score[x]++;
        num=max(1,(int)(1.0*i*m/100));
        int sum=0;
        for(int j=600;j>=0;j--){
            sum+=score[j];
            if(sum>=num){
                mark=j;
                break;
            }
        }
        cout<<mark<<" ";
    }
    return 0;
}
