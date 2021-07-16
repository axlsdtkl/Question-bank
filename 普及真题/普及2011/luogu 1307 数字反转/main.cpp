#include<bits/stdc++.h>
using namespace std;
int cnt,l,b[100];
int main()
{
	int a;
	cin>>a;
	if(a<0)
	{
		cout<<"-";
		a=-a;
	}
	if(a==0)
	{
		cout<<0<<endl;
	}
	while(a>0)
	{
		cnt++;
		b[cnt]=a%10;
		a/=10;
	}
	l=1;
	while(b[l]==0)l++;
	for(int i=l;i<=cnt;i++)cout<<b[i];
	return 0;
}