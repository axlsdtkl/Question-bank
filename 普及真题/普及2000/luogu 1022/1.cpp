#include<bits/stdc++.h>
using namespace std;
char s[1100],ch;
int bj,mark,x,len,fh;
double a,b;
int main(){
	//freopen("1.in","r",stdin);
	scanf("%s",s+1);len=strlen(s+1);
	s[len+1]='+';len++;
	bj=0;mark=1;fh=1;
	for(int i=1;i<=len;i++){
		if(s[i]>='0'&&s[i]<='9')x=x*10+s[i]-'0';
		if(s[i]=='+'||s[i]=='-'||s[i]=='='){
			if(bj==0)a+=fh*mark*x;
				else b+=fh*mark*x;
			x=0;
			if(s[i]=='+')fh=1;
			if(s[i]=='-')fh=-1;
			if(s[i]=='='){
				mark=-1;
				fh=1;
			}
			bj=0;
		}
		if(s[i]>='a'&&s[i]<='z'){
			if(x==0)x=1;
			ch=s[i],bj=1;
		}
	}
	printf("%c=%.3lf\n",ch,(-a)/b);
	return 0;
}
	
		
