#include<cstdio>
int x,y,i,j,z,ans;
int gcd(int x,int y)
{
	if(y==0)return x;
	return gcd(y,x%y);
}
int main()
{
	scanf("%d%d",&x,&y);
	if(y%x!=0)
	{
		printf("0\n");
		return 0;
	}
	z=y/x;
	for(i=1;i<=z;i++)
	if(z%i==0)
	{
		j=z/i;
		if(gcd(i,j)==1)ans++;
	}
	printf("%d\n",ans);
	return 0;
}
