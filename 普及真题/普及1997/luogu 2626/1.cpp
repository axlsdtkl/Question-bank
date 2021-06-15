#include<bits/stdc++.h>
#define LL long long
LL a[100],n,i,cnt,q[100];
int main(){
	scanf("%lld",&n);
	a[1]=a[2]=1;
	for(i=3;i<=n;i++)a[i]=(a[i-2]+a[i-1])%((LL)2147483648);
	printf("%lld=",a[n]);
	for(i=2;i<=sqrt(a[n]);i++){
		while(a[n]%i==0)a[n]/=i,cnt++,q[cnt]=i;
	}
	if(a[n]>1)cnt++,q[cnt]=a[n];
	printf("%lld",q[1]);
	for(i=2;i<=cnt;i++)printf("*%lld",q[i]);
	printf("\n");
	return 0;
}
