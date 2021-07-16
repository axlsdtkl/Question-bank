#include<bits/stdc++.h>
using namespace std;
char s1[2000000],s2[20000000];
int ans=0;
int t,mark = -1;
int len1;
int work(int x)
{
	for(int i=0;i<len1;i++)
		if(s1[i]!=s2[x+i])return 0;
	return 1;
}
int main(){
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	cin>>s1;
	len1=strlen(s1);
	for(int i=0;i<len1;i++)
	{
		if(s1[i] > 'Z')
		{
			s1[i] += ('Z'-'z');
		}
	}
	gets(s2);
	gets(s2);
	int len2 = strlen(s2);
	for(int i=0;i<len2;i++)
	{
		if(s2[i] > 'Z')
		{
			s2[i] += ('Z'-'z');
		}
	}
	for(int i=0;i<=len2-len1;i++){
		if((i==0||s2[i-1]==' ')&&(i+len1==len2||s2[i+len1]==' ')&&work(i)==1)
		{
			ans++;
			if(mark==-1)mark=i;
		}
	}
	if(ans == 0)
	{
	    cout << "-1" <<endl;
 	}
	else
	{
	    cout << ans << " " << mark; 
	}
	return 0;
}
