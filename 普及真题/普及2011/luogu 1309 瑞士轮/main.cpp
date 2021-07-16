#include<bits/stdc++.h>
using namespace std;
struct arr{
    int id,s,w;
}a[210000],b[210000],c[210000];
int n,r,q,cnt1,cnt2;
int cmp(arr a,arr b){
    if(a.s>b.s)return 1;
    if(a.s<b.s)return 0;
    return a.id<b.id;
}
void merge(){
    int l1,l2;
    b[cnt1+1].s=1<<30;
    c[cnt2+1].s=1<<30;
    l1=1;
    l2=1;
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(l1>cnt1){
            cnt++;
            a[cnt]=c[l2];
            l2++;
        }else if(l2>cnt2){
            cnt++;
            a[cnt]=b[l1];
            l1++;
        }else if(cmp(b[l1],c[l2])){
            cnt++;
            a[cnt]=b[l1];
            l1++;
        }else{
            cnt++;
            a[cnt]=c[l2];
            l2++;
        }
    }
}
int main(){
    cin>>n>>r>>q;
    n*=2;
    for(int i=1;i<=n;i++){
        cin>>a[i].s;
        a[i].id=i;
    }
    for(int i=1;i<=n;i++)cin>>a[i].w;
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=r;i++){
        cnt1=0;
        cnt2=0;
        for(int j=1;j<=n;j++){
            if(j%2==1){
                if(a[j].w>a[j+1].w){
                    cnt1++;
                    a[j].s++;
                    b[cnt1]=a[j];
                    cnt2++;
                    c[cnt2]=a[j+1];
                }else{
                    cnt1++;
                    a[j+1].s++;
                    b[cnt1]=a[j+1];
                    cnt2++;
                    c[cnt2]=a[j];
                }
            }
        }
        merge();
    }
    cout<<a[q].id<<endl;
}
