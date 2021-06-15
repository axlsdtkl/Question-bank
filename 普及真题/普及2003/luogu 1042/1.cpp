#include<bits/stdc++.h>
char c,s[510000];
int i,x,y,n;
int main(){
	for(;;){
		c=getchar();
		if(c>='A'&&c<='Z')n++,s[n]=c;
		if(c=='E')break;
	}
	n--;
	x=y=0;
	for(i=1;i<=n;i++){
		if(s[i]=='W')x++;else y++;
		if(x>=11||y>=11)
			if(abs(x-y)>=2){
				printf("%d:%d\n",x,y);
				x=y=0;
			}
	}
	printf("%d:%d\n\n",x,y);
	
	x=y=0;
	for(i=1;i<=n;i++){
		if(s[i]=='W')x++;else y++;
		if(x>=21||y>=21)
			if(abs(x-y)>=2){
				printf("%d:%d\n",x,y);
				x=y=0;
			}
	}
	printf("%d:%d\n\n",x,y);
	return 0;
}
