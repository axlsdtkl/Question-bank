#include<cstdio>
int n,m,i,j,k;
int a[110][110];
char s[110][110];
int dx[8]={-1,-1,-1,0,0,1,1,1};
int dy[8]={-1,0,1,-1,1,-1,0,1};
int main()
{
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)scanf("%s",s[i]+1);
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
		if(s[i][j]!='*')
			for(k=0;k<8;k++)
			if(s[i+dx[k]][j+dy[k]]=='*')a[i][j]++;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		if(s[i][j]=='*')printf("*");
			else printf("%d",a[i][j]);
		printf("\n");
	}
	return 0;
}