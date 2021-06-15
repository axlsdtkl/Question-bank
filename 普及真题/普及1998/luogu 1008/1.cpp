#include<bits/stdc++.h>
int flag[10];
int q[20];
void dfs(int x){
	int a,b,c,i;
	if(x==10){
		a=q[1]*100+q[2]*10+q[3];
		b=q[4]*100+q[5]*10+q[6];
		c=q[7]*100+q[8]*10+q[9];
		if(a*2==b&&a*3==c)printf("%d %d %d\n",a,b,c);
		return;
	}
	for(i=1;i<=9;i++)
	if(flag[i]==0){
		flag[i]=1;
		q[x]=i;
		dfs(x+1);
		flag[i]=0;
	}
}
int main(){
	dfs(1);
	return 0;
}
