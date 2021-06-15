#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<stack>

using namespace std;
stack<int>st;
int n,m,x;
int main(){
	freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	//freopen("1.out")
	cin>>n>>m;
	cout<<n<<'=';
	while(n!=0){
		x=n%m;

		if(x<0)x-=m,n+=m;
		//cout<<"aaa"<<x<<endl;
		n/=m;
		//cout<<x<<endl;
		st.push(x);
	}
	while(st.size()){
		x=st.top();
		//printf("%d\n",x);
		//cout<<x<<endl;
		st.pop();
		char ch;
		if(x>=10)ch='A'+x-10;
		else ch=x+'0';
		printf("%c",ch);
	}
	cout<<"(base"<<m<<")";
	return 0;
}