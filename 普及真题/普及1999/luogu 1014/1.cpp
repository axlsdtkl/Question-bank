#include<bits/stdc++.h>
int n,x,y,fx,i;
int main(){
	scanf("%d",&n);
	x=1;y=1;fx=0;
	for(i=2;i<=n;i++){
		if(fx==0&&x==1)y++,fx=1;
			else if(fx==1&&y==1)x++,fx=0;
				else if(fx==0)x--,y++;
					else x++,y--;
	}
	printf("%d/%d\n",x,y);
	return 0;
}
		
