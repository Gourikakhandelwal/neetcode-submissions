class Solution {
public:
void dfs(vector<vector<char>> &board,int i,int j,vector<vector<int>> &visit){
    vector<int> row={-1,1,0,0};
    vector<int> col={0,0,-1,1};
    for(int k=0;k<4;k++){
        int r=i+row[k];
        int c=j+col[k];
        if(r>=0 && r<board.size() && c>=0 && c<board[0].size() && board[r][c]=='O' && visit[r][c]==0){
            visit[r][c]=1;
            dfs(board,r,c,visit);
        }
    }
}
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>> visit(n,vector<int>(m,0));
        for(int i=0;i<board.size();i++){

            if(board[i][0]=='O' && visit[i][0]==0){
                visit[i][0]=1;
            dfs(board,i,0,visit);
            }
            if(board[i][m-1]=='O' && visit[i][m-1]==0){
                visit[i][m-1]=1;
                dfs(board,i,m-1,visit);
            }
            
        }
        for(int j=0;j<board[0].size();j++){
            if(board[0][j]=='O' && visit[0][j]==0){
                visit[0][j]=1;
                dfs(board,0,j,visit);
            }
            if(board[n-1][j]=='O' && visit[n-1][j]==0){
                visit[n-1][j]=1;
                dfs(board,n-1,j,visit);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visit[i][j]==0 && board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
    }
};
