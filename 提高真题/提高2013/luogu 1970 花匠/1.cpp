#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,ans,high,a[110000],now;
int main(){
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	ans=1;
	high=a[1];
	now=0;
	for(int i=2;i<=n;i++){
		if(now==0){
			if(a[i]>high){
				ans++;
				now=1;
				high=a[i];
			}else if(a[i]<high){
				ans++;
				now=-1;
				high=a[i];
			}
		}else if(now==1){
			if(a[i]>high)high=a[i];
			else if(a[i]<high){
				now=-1;
				ans++;
				high=a[i];
			}
		}else if(now==-1){
			if(a[i]<high)high=a[i];
			else if(a[i]>high){
				now=1;
				ans++;
				high=a[i];
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}