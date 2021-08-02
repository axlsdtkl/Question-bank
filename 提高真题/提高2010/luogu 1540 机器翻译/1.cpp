#include<bits/stdc++.h>
using namespace std;
int a[1100],l=1,r=0,m,n,x,ans;
int check(int x){
	for(int i=l;i<=r;i++)
		if(a[i]==x)return 1;
	return 0;
}
int main(){
	cin>>m>>n;
	while(n--){
		cin>>x;
		if(check(x)==1)continue;
		ans++;
		if(r-l+1==m)l++;
		r++;
		a[r]=x;
	}
	cout<<ans<<endl;
}