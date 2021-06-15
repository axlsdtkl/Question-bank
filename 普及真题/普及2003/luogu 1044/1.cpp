#include<cstdio>
int i,j,n;
int a[100];
int main()
{
	a[0]=1;a[1]=1;
	for(i=2;i<=18;i++)
		for(j=0;j<i;j++)a[i]+=a[j]*a[i-1-j];
	scanf("%d",&n);
	printf("%d\n",a[n]);
	return 0;
}
