#include<bits/stdc++.h>
using namespace std;
long long a[110000];
int main(){
	long long n,m,s1,s2,p1,p2,t=0,l=0,h,min1=1000000000,ll,tt;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cin>>m>>p1>>s1>>s2;
	for(int i=1;i<m;i++){
		l=l+a[i]*(m-i);
	}
	for(int i=m+1;i<=n;i++){
		t=t+a[i]*(i-m);
	}
	
	if(p1<m){
		l=l+(m-p1)*s1;
	}
	if(p1>m){
		t=t+(p1-m)*s1;
	}
	

	for(long long i=1;i<=n;i++){
		if(i<m){
			ll=l+(m-i)*s2;
			tt=t;
		}
		if(i>=m){
			ll=l;
			tt=t+(i-m)*s2;
		}
		if(ll>tt){
			if(min1>ll-tt){
				min1=ll-tt;
				p2=i;
			}
		}
		else{
			if(min1>tt-ll){
				min1=tt-ll;
				p2=i;
			}
		}
		
	}
		
	cout<<p2<<endl;
	return 0;
}