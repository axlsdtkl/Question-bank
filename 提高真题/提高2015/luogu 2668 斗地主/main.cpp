#include<bits/stdc++.h>
using namespace std;
int T,n,ans,sum[20],x,y;
void dfs(int x){
    if(x>=ans)return;
    int k=0;
    for(int i=3;i<=14;i++){
        if(sum[i]==0)k=0;
        else{
            k++;
            if(k>=5){
                for(int j=i;j>=i-k+1;j--)sum[j]--;
                dfs(x+1);
                for(int j=i;j>=i-k+1;j--)sum[j]++;
            }
        }
    }
    k=0;
    for(int i=3;i<=14;i++){
        if(sum[i]<=1)k=0;
        else{
            k++;
            if(k>=3){
                for(int j=i;j>=i-k+1;j--)sum[j]-=2;
                dfs(x+1);
                for(int j=i;j>=i-k+1;j--)sum[j]+=2;
            }
        }
    }
    k=0;
    for(int i=3;i<=14;i++){
        if(sum[i]<=2)k=0;
        else{
            k++;
            if(k>=2){
                for(int j=i;j>=i-k+1;j--)sum[j]-=3;
                dfs(x+1);
                for(int j=i;j>=i-k+1;j--)sum[j]+=3;
            }
        }
    }
    for(int i=2;i<=14;i++){
        if(sum[i]<=3){
            if(sum[i]<=2)continue;
            sum[i]-=3;
            for(int j=2;j<=15;j++){
                if(sum[j]<=0||j==i)continue;
                sum[j]--;
                dfs(x+1);
                sum[j]++;
            }
            for(int j=2;j<=14;j++){
                if(sum[j]<=1||j==i)continue;
                sum[j]-=2;
                dfs(x+1);
                sum[j]+=2;
            }
            sum[i]+=3;
        }else{
            sum[i]-=3;
            for(int j=2;j<=15;j++){
                if(sum[j]<=0||j==i)continue;
                sum[j]-=2;
                dfs(x+1);
                sum[j]+=2;
            }
            sum[i]+=3;
            sum[i]-=4;
            for(int j=2;j<=15;j++){
                if(sum[j]<=0||j==i)continue;
                sum[j]--;
                for(int k=2;k<=15;k++){
                    if(sum[k]<=0||j==k)continue;
                    sum[k]--;
                    dfs(x+1);
                    sum[k]++;
                }
                sum[j]++;
            }
            for(int j=2;j<=14;j++){
                if(sum[j]<=1||j==i)continue;
                sum[j]-=2;
                for(int k=2;k<=14;k++){
                    if(sum[k]<=1||j==k)continue;
                    sum[k]-=2;
                    dfs(x+1);
                    sum[k]+=2;
                }
                sum[j]+=2;
            }
            sum[i]+=4;
        }
    }
    for(int i=2;i<=15;i++)if(sum[i])x++;
    ans=min(ans,x);
}
int main(){
    //freopen("1.in","r",stdin);
    cin>>T>>n;
    while(T--){
        ans=10000000;
        memset(sum,0,sizeof(sum));
        for(int i=1;i<=n;i++){
            cin>>x>>y;
            if(x==0)sum[15]++;
            else if(x==1)sum[14]++;
            else sum[x]++;
        }
        dfs(0);
        cout<<ans<<endl;
    }
    return 0;
}
