class Solution {
public:
vector<vector<string>> res;
unordered_set<int> column;
unordered_set<int> diag;
unordered_set<int> anti;
int N;
void func(vector<string>& board,int row){
    if(row==N){
        res.push_back(board);
        return ;
    }
    for(int col=0;col<N;col++){
        int x=col;
        int y=row+col;
        int z=row-col;
        if(column.find(x)!=column.end()||diag.find(y)!=diag.end()||anti.find(z)!=anti.end()){
            continue;
        }
        column.insert(x);
        diag.insert(y);
        anti.insert(z);

        board[row][col]='Q';
        func(board,row+1);
        board[row][col]='.';
        column.erase(x);
        diag.erase(y);
        anti.erase(z);
    }
}
    vector<vector<string>> solveNQueens(int n) {
        N=n;
       vector<string> board(n,string(n,'.'));
        func(board,0);
        return res;
    }
};