#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100005;
const ll INF=2147483647;
struct data{
    ll id,al;
    bool operator <(const data &y)const{
        return al<y.al;
    }
};
ll f[21][N][2],da[21][N][2],db[21][N][2];
double ans=(1<<30);
ll n,h[N],x0,m,s[N],x[N],ga,gb,mark,suma,sumb,xx,yy;
multiset<data>S;
void calc(ll s,ll d){
    suma=0;
    sumb=0;
    for(int i=20;i>=0;i--){
        if(suma+sumb+da[i][s][0]+db[i][s][0]<=d){
            suma+=da[i][s][0];
            sumb+=db[i][s][0];
            s=f[i][s][0];
        }
    }
}
void pre(){
    data now;
    h[0]=-INF;h[n+1]=INF;
    now.id=0;now.al=-INF;
    S.insert(now);
    S.insert(now);
    now.id=n+1;now.al=INF;
    S.insert(now);
    S.insert(now);
    for(ll i=n;i>=1;i--){
        now.id=i;
        now.al=h[i];
        S.insert(now);
        set<data>::iterator p=S.lower_bound(now);
        p--;
        ll lt=(*p).id;ll lh=(*p).al;
        p++;p++;
        ll nt=(*p).id;ll nh=(*p).al;
        p--;
        if(abs(nh-h[i])>=abs(h[i]-lh)){
            gb=lt;
            p--;p--;
            if(abs(nh-h[i])>=abs(h[i]-(*p).al))ga=(*p).id;
            else ga=nt;
        }else{
            gb=nt;
            p++;p++;
            if(abs(h[i]-lh)<=abs(h[i]-(*p).al))ga=lt;
            else ga=(*p).id;
        }
        f[0][i][0]=ga;
        f[0][i][1]=gb;
        da[0][i][0]=abs(h[i]-h[ga]);
        db[0][i][1]=abs(h[i]-h[gb]);
    }
    for(int i=1;i<=20;i++){
        for(int j=1;j<=n;j++){
            for(int k=0;k<2;k++){
                if(i==1){
                    f[i][j][k]=f[0][f[0][j][k]][1-k];
                    da[i][j][k]=da[i-1][j][k]+da[0][f[0][j][k]][1-k];
                    db[i][j][k]=db[i-1][j][k]+db[0][f[0][j][k]][1-k];;
                }else{
                    f[i][j][k]=f[i-1][f[i-1][j][k]][k];
                    da[i][j][k]=da[i-1][j][k]+da[i-1][f[i-1][j][k]][k];
                    db[i][j][k]=db[i-1][j][k]+db[i-1][f[i-1][j][k]][k];
                }
            }
        }
    }
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>h[i];
    cin>>x0;
    cin>>m;
    pre();
    for(int i=1;i<=n;i++){
        calc(i,x0);
        double res=(double)(suma)/(double)(sumb);
        if(res<ans){
            ans=res;
            mark=i;
        }else if(res==ans){
            if(h[i]>h[mark])mark=i;
        }
    }
    cout<<mark<<endl;
    for(int i=1;i<=m;i++){
        cin>>xx>>yy;
        calc(xx,yy);
        cout<<suma<<" "<<sumb<<endl;
    }
    return 0;
}
