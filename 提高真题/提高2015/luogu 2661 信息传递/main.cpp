#include<bits/stdc++.h>
using namespace std;
const int N=210000;
int n,x,In[N],flag[N],ans=210000,sum;
vector<int>e[N];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x;
        e[i].push_back(x);
        In[x]++;
    }
    queue<int>q;
    for(int i=1;i<=n;i++){
        if(In[i]==0)q.push(i);
    }
    while(q.size()){
        x=q.front();
        q.pop();
        flag[x]=1;
        for(int i=0;i<e[x].size();i++){
            int y=e[x][i];
            In[y]--;
            if(In[y]==0)q.push(y);
        }
    }
    for(int i=1;i<=n;i++){
        if(flag[i]==0){
            flag[i]=1;
            int now=i;
            int sum=1;
            while(1){
                int yes=0;
                for(int j=0;j<e[now].size();j++){
                    int y=e[now][j];
                    if(flag[y]==0){
                        yes=y;
                    }
                }
                if(yes==0)break;
                now=yes;
                flag[now]=1;
                sum++;
            }
            ans=min(ans,sum);
        }
    }
    cout<<ans<<endl;
    return 0;
}
