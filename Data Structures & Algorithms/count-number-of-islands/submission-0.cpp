class Solution {
public:
void func(int i,int j,vector<vector<char>> &grid,vector<vector<int>> &visit){
    visit[i][j]=1;
    int row=i;
    int col=j;
    vector<int> r={-1,1,0,0};
    vector<int> c={0,0,-1,1};
    for(int k=0;k<4;k++){
        int nr=row+r[k];
        int nc=col+c[k];
        if(nr>=0 && nr<grid.size() && nc>=0 && nc<grid[0].size() && grid[nr][nc]=='1' && visit[nr][nc]==0){
            func(nr,nc,grid,visit);
        }
    }
}
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> visit(n,vector<int>(m,0));
        
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && visit[i][j]==0){
                    cnt++;
                    func(i,j,grid,visit);
                }
            }
        }
        return cnt;

    }
};
