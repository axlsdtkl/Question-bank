#include<bits/stdc++.h>
int n;
char s[100000];
int i,len,j,ans,a[100000],b[100000];
int work(int len){
	int i;
	for(i=1;i<=len/2;i++)if(a[i]!=a[len-i+1])return 0;
	return 1;
}
int main(){
	scanf("%d",&n);
	scanf("%s",s+1);len=strlen(s+1);
	for(i=1;i<=len;i++){
		if(s[len-i+1]>='0'&&s[len-i+1]<='9')a[i]=s[len-i+1]-'0';
			else a[i]=s[len-i+1]-'A'+10;
	}
	if(work(len)==1){
		printf("STEP=%d\n",0);
		return 0;
	}
	for(i=1;i<=30;i++){
		ans++;
		for(j=1;j<=len;j++)b[j]=a[j]+a[len-j+1];
		for(j=1;j<=len;j++)b[j+1]+=b[j]/n,b[j]%=n;
		if(b[len+1])len++;
		for(j=1;j<=len;j++)a[j]=b[j];
		if(work(len)==1){
			printf("STEP=%d\n",ans);
			return 0;
		}
	}
	printf("Impossible!\n");
	return 0;
}
