#include<bits/stdc++.h>
using namespace std;
char s[10];
int a,b,ans;
int gcd(int a,int b){
	if(b==0)return a;
	else return gcd(b,a%b);
}
int main(){
    cout<<1<<endl;
    cin>>a;
    cin>>b;
    ans=gcd(a,b);
	cout<<ans<<endl;
	return 0; 
}
