#include<bits/stdc++.h>
using namespace std;
double s;
int n,i;
int main(){
	scanf("%d",&n);
	while(s<=n){
		i++;
		s+=1.0/i;
	}
	printf("%d\n",i);
	return 0;
}
