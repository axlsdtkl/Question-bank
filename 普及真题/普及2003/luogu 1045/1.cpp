#include<bits/stdc++.h>
using namespace std;
#define LL long long
LL a[1000];
LL n,js,cnt;
int main(){
	scanf("%lld",&n);
	printf("%lld\n",(int)(log10(2)*n)+1);
	a[1]=1;
	for(int i=1;i<=n/30;i++){
		for(int j=1;j<=500;j++)a[j]*=(1<<30);
		for(int j=1;j<=500;j++)a[j+1]+=a[j]/10,a[j]%=10;
	}
	for(int i=1;i<=n%30;i++){
		for(int j=1;j<=500;j++)a[j]<<=1;
		for(int j=1;j<=500;j++)a[j+1]+=a[j]/10,a[j]%=10;
	}
	a[1]--;
	js=1;
	while(a[js]<0){
		a[js]+=10;
		js++;
		a[js]--;
	}
	for(int i=500;i>0;i--){
		cnt++;
		printf("%lld",a[i]);
		if(cnt==50)printf("\n"),cnt=0;
	}
	return 0;
}
