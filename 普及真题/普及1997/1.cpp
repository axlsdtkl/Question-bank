#include<bits/stdc++.h>
using namespace std;
int x,p,i;
int a[1000];
int main(){
	p=2;
	i=1;
	cin>>x;
	while(x!=1){
		if(x%p==0){
			x=x/p;
			a[i]=p;
			i++;
			p=1;
		}
		p++;
	}
	for(int l=1;l<i;l++){
		if(i-l==1){
			cout<<a[l];
		}
		else
		cout<<a[l]<<"*";
	}
}
