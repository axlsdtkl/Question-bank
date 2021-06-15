#include<bits/stdc++.h>
using namespace std;
int a,b,d,e,f[10005],g[10005],h[10005],i[10005];
double c;
int main()
{
	cin>>a>>b;
	for(int j=0;j<a;j++)
	{
		cin>>f[j];
		c+=f[j];
	}
	c/=b;
	if(b%2==1) b++;
	for(int j=0;j<b/2;j++)
	{
		e=0;
		int l,m;
		for(int k=j+1;k<b;k++)
		{
			if(c>f[j]+f[k])	h[k]=c-f[j]-f[k];
			else h[k]=f[j]+f[k]-c;
			if(h[k]<l&&g[k]==0)
			{
				e=1;
				l=h[k];
				m=k;
			}
		}
		i[d]=f[j]+f[m];
		d++,g[j]++,g[m]++;
	}
	if(e==0)
	{
		for(int j=0;j<b;j++)
		{
			if(g[j]==0)
			{
				sort(i,i+b/2);
				i[0]+=f[j];
				sort(i,i+b/2);
				cout<<i[b/2];
				return 0;
			}
		}
	}
	sort(i,i+b/2);
	cout<<i[b/2];
	return 0;
}
