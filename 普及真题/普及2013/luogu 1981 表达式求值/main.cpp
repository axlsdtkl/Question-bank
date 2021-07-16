#include<bits/stdc++.h>
int len,x,i,top,st[210000],ans;
char s[1000000];
int main(){
	scanf("%s",s+1);len=strlen(s+1);
	len++;s[len]='+';
	x=0;
	for(i=1;i<=len;i++){
		if(s[i]>='0'&&s[i]<='9')x=x*10+s[i]-'0',x%=10000;
		else{
			top++;st[top]=x;x=0;
			if(st[top-1]==-2){
				x=st[top-2]*st[top];
				x%=10000;
				top--;top--;
				st[top]=x;
				x=0;
			}
		}
		if(s[i]=='+')top++,st[top]=-1;
		if(s[i]=='*')top++,st[top]=-2;
	}
	for(i=1;i<=top;i++)if(st[i]>=0)ans+=st[i],ans%=10000;
	printf("%d\n",ans);
	return 0;
}