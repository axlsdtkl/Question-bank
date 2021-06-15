#include<bits/stdc++.h>
using namespace std;
int n,m,f,c;
int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		for(int l=1;l<=n;l++){
			if(i==l){
				f+=(m-i+1)*(n-l+1);
			}
			if(i!=l){
			c+=(m-i+1)*(n-l+1);
			}
		}
	}
	cout<<f<<" "<<c;
	return 0;
}
