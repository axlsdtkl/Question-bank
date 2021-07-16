#include<bits/stdc++.h>
using namespace std;
int cnt,l,b[100],ans;
int main()
{
	string s;
	getline(cin,s);
	int len = s.length();
	for(int i=0;i<len;i++)
		if((s[i] >= '0'&&s[i] <= '9')||(s[i] >= 'a'&&s[i] <= 'z')||(s[i] >= 'A'&&s[i] <= 'Z'))ans++;
	cout<<ans<<endl;
}