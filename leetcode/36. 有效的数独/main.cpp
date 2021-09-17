class Solution {
public:
    const static int N=10;
    int yes=1;
    int a[N][N],flag[N];
    int judgeRow(){
        for(int i=1;i<=9;i++){
            memset(flag,0,sizeof(flag));
            for(int j=1;j<=9;j++){
                if(a[i][j]==0)continue;
                flag[a[i][j]]++;
                if(flag[a[i][j]]==2)return 0;
            }
        }
        return 1;
    }
    int judgeCol(){
        for(int j=1;j<=9;j++){
            memset(flag,0,sizeof(flag));
            for(int i=1;i<=9;i++){
                if(a[i][j]==0)continue;
                flag[a[i][j]]++;
                if(flag[a[i][j]]==2)return 0;
            }
        }
        return 1;
    }
    int judgeMat(){
        for(int h=1;h<=3;h++){
            for(int l=1;l<=3;l++){
                int x=(h-1)*3+1;
                int y=(l-1)*3+1;
                memset(flag,0,sizeof(flag));
                for(int i=x;i<=x+2;i++){
                    for(int j=y;j<=y+2;j++){
                        if(a[i][j]==0)continue;
                        flag[a[i][j]]++;
                        if(flag[a[i][j]]==2)return 0;
                    }
                }
            }
        }
        return 1;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.')
                    a[i+1][j+1]=board[i][j]-'0';
            }
        }
        if(judgeRow()==0)yes=0;
        if(judgeCol()==0)yes=0;
        if(judgeMat()==0)yes=0;
        return yes;
    }
};