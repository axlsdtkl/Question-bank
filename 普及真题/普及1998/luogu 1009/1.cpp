#include<bits/stdc++.h>
int n,i,j,x,ans,w;
int a[200],b[200];
int main(){
	a[1]=1;
	scanf("%lld",&n);
	for(i=1;i<=n;i++){
		for(j=1;j<=100;j++)a[j]*=i;
		for(j=1;j<=100;j++)a[j+1]+=a[j]/10,a[j]%=10;
		for(j=1;j<=100;j++)b[j]+=a[j];
		for(j=1;j<=100;j++)b[j+1]+=b[j]/10,b[j]%=10;
	}
	w=100;
	while(w>1&&b[w]==0)w--;
	for(i=w;i>0;i--)printf("%d",b[i]);
	printf("\n");
	return 0;
}

