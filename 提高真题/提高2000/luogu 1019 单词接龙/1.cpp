#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
int flag[100],f[100][100];
char s[100][100];
int n,ans;
int work(int x,char sa[100],char sb[100]){
	int len1=strlen(sa+1);
	int len2=strlen(sb+1);
	int num=0;
	for(int i=len1-x+1;i<=len1;i++){
		num++;
		if(sa[i]!=sb[num])return 0;
	}
	return 1;
}
void dfs(int now,int x){
	if(x>ans)ans=x;
	for(int i=1;i<=n;i++)
		if(flag[i]<2){
			if(f[now][i]>0){
				flag[i]++;
				dfs(i,x+strlen(s[i]+1)-f[now][i]);
				flag[i]--;
			}
		}
}
int main(){
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);

	cin>>n;
	for(int i=1;i<=n;i++)cin>>(s[i]+1);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			int len1=strlen(s[i]+1);
			int len2=strlen(s[j]+1);
			for(int k=1;k<=len1-1;k++){
				if(k>=len2)continue;
				if(work(k,s[i],s[j])){
					f[i][j]=k;
					//cout<<i<<" "<<j<<" "<<f[i][j]<<endl;
					break;
				}
			}
		}
	char ch;
	cin>>ch;
	for(int i=1;i<=n;i++){
		if(s[i][1]==ch){
			flag[i]++;
			dfs(i,strlen(s[i]+1));	
		}
	}

	cout<<ans<<endl;
	return 0;
}