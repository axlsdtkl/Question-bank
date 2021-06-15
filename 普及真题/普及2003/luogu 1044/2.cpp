#include<cstdio>
int n,i,a[20],j,x;
int main(){
	a[0]=1;
	a[1]=1;
	scanf("%d",&x);
	for(i=2;i<=18;i++){
		int sum=0;
		for(j=0;j<=i-1;j++)
		sum+=a[j]*a[i-1-j];
		a[i]=sum;
	}
	printf("%d\n",a[x]);
	return 0;
}
