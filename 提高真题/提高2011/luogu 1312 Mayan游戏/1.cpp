#include<bits/stdc++.h>
using namespace std;
int n,x,a[6][8],ans[6][3],b[6][8],last[6][6][8],flag[6][8];
int check(){
    for(int i=1;i<=5;i++){
        if(a[i][1]>0)return 0;
    }
    return 1;
}
void update(){
    for(int i=1;i<=5;i++){
        int cnt=0;
        for(int j=1;j<=7;j++){
            if(a[i][j]==0)cnt++;
            else{
                if(cnt==0)continue;
                a[i][j-cnt]=a[i][j];
                a[i][j]=0;
            }
        }
    }
}
bool remove(){
    for(int i=1;i<=5;i++){
        for(int j=1;j<=7;j++){
            if(i>1&&i<5){
                if(a[i][j]&&a[i][j]==a[i-1][j]&&a[i][j]==a[i+1][j]){
                    flag[i][j]=flag[i-1][j]=flag[i+1][j]=1;
                }
            }
            if(j>1&&j<7){
                if(a[i][j]&&a[i][j]==a[i][j-1]&&a[i][j]==a[i][j+1]){
                    flag[i][j]=flag[i][j-1]=flag[i][j+1]=1;
                }
            }
        }
    }
    int yes=0;
    for(int i=1;i<=5;i++){
        for(int j=1;j<=7;j++){
            if(flag[i][j]){
                yes=1;
                flag[i][j]=0;
                a[i][j]=0;
            }
        }
    }
    if(yes==1)return 1;
    return 0;
}
void move(int x,int y,int z){
    swap(a[x][y],a[x+z][y]);
    update();
    while(remove())update();
}
void dfs(int de){
    if(check()){
        for(int i=1;i<=n;i++){
            for(int j=0;j<3;j++)cout<<ans[i][j]<<" ";
            cout<<endl;
        }
        exit(0);
    }
    if(de>n)return;
    for(int i=1;i<=5;i++){
        for(int j=1;j<=7;j++)last[de][i][j]=a[i][j];
    }
    for(int i=1;i<=5;i++){
        for(int j=1;j<=7;j++){
            if(i<5&&a[i][j]>0&&a[i][j]!=a[i+1][j]){
                move(i,j,1);
                ans[de][0]=i-1;
                ans[de][1]=j-1;
                ans[de][2]=1;
                dfs(de+1);
                for(int ia=1;ia<=5;ia++){
                    for(int ja=1;ja<=7;ja++)a[ia][ja]=last[de][ia][ja];
                }
            }
            if(i>1&&a[i][j]>0&&a[i-1][j]==0){
                move(i,j,-1);
                ans[de][0]=i-1;
                ans[de][1]=j-1;
                ans[de][2]=-1;
                dfs(de+1);
                for(int ia=1;ia<=5;ia++){
                    for(int ja=1;ja<=7;ja++)a[ia][ja]=last[de][ia][ja];
                }
            }
        }
    }
}

int main(){
    cin>>n;
    for(int i=1;i<=5;i++){
        for(int j=1;j<=8;j++){
            cin>>x;
            if(x==0)break;
            a[i][j]=x;
        }
    }
    dfs(1);
    cout<<-1<<endl;
    return 0;
}
