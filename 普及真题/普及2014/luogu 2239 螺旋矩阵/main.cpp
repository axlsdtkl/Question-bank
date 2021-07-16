#include<bits/stdc++.h>
using namespace std;
int n,x,y,a,i=1,j=1,b;
int f[3100][3100];
int main(){
    cin>>n>>x>>y;
    memset(f,42,sizeof(f));//全部变成数字
    for(int i=1;i<=n;i++){//把需要的n*n挖空
        for(int j=1;j<=n;j++){
            f[i][j]=0;
        }
    }
    while(1)
    {
        b++;
        if(a==0)
        {
            f[i][j]=b;
            if(f[i][j+1]!=0)
            {
                a=1;
                i++;
            }
            else j++;
        }
        else if(a==1)
        {
            f[i][j]=b;
            if(f[i+1][j]!=0)
            {
                a=2;
                j--;
            }
            else i++;
        }
        else if(a==2)
        {
            f[i][j]=b;
            if(f[i][j-1]!=0)
            {
                a=3;
                i--;
            }
            else j--;
        }
        else if(a==3)
        {
            f[i][j]=b;
            if(f[i-1][j]!=0)
            {
                a=0;
                j++;
            }
            else i--;
        }
        if(f[x][y]!=0)break;
    }

    cout<<f[x][y]<<endl;
    return 0;
}
