#include<bits/stdc++.h>
int two[20],n,i;
void work(int n){
	int i;
	for(i=16;i>=0;i--)
	if(n>=two[i]){
		n-=two[i];
		if(i==0)printf("2(0)");
		else if(i==1)printf("2");
		else {
			printf("2(");
			work(i);
			printf(")");
		}
		if(n>0)printf("+");
	}
}
int main(){
	scanf("%d",&n);
	two[0]=1;
	for(i=1;i<=16;i++)two[i]=two[i-1]*2;
	work(n);
	printf("\n");
	return 0;
}
