#include<bits/stdc++.h>
using namespace std;
const int N=1100000;
int T,a[N],n,m,ans,x,y;
int read(){
    char ch=getchar();
    int x=0;
    while(ch<'0'||ch>'9')ch=getchar();
    while(ch>='0'&&ch<='9'){
        x=(x<<3)+(x<<1)+ch-'0';
        ch=getchar();
    }
    return x;
}
void write(int x){
    if(x>=10)write(x/10);
    putchar('0'+x%10);
}
int main(){
    cin>>T;
    for(int t=1;t<=T;t++){
        if(t==1){
            n=read();
            for(int i=1;i<=n;i++)a[i]=read();
        }else{
            m=read();
            while(m--){
                x=read();
                y=read();
                a[x]=y;
            }
        }
        deque<pair<int,int> >q1,q2;
        for(int i=1;i<=n;i++)q1.push_back({a[i],i});
        for(;;){
            if(q1.size()+q2.size()==2){
                ans=1;
                break;
            }
            int x,y,id;
            y=q1.front().first,q1.pop_front();
            if(q2.empty()||!q1.empty()&&q1.back()>q2.back()){
                x=q1.back().first,id=q1.back().second,q1.pop_back();
            }else{
                x=q2.back().first,id=q2.back().second,q2.pop_back();
            }
            pair<int,int>now=make_pair(x-y,id);
            if(q1.empty()||q1.front()>now){
                ans=q1.size()+q2.size()+2;
                int cnt=0;
                for(;;){
                    cnt++;
                    if(q1.size()+q2.size()==1){
                        if(cnt%2==0)ans--;
                        break;
                    }
                    int x,id;
                    if(q2.empty()||!q1.empty()&&q1.back()>q2.back()){
                        x=q1.back().first,id=q1.back().second,q1.pop_back();
                    }else{
                        x=q2.back().first,id=q2.back().second,q2.pop_back();
                    }
                    now={x-now.first,id};
                    if((q1.empty()||now<q1.front()&&(q2.empty()||now<q2.front()))){
                        
                    }else{
                        if(cnt%2==0)ans--;
                        break;
                    }
                }
                break;
            }else q2.push_front(now);
        }
        write(ans);
        putchar('\n');
    }
    return 0;
}
