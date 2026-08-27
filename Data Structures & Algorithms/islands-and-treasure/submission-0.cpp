class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int INF = INT_MAX;

        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int,int>> q;

        // Start BFS from all treasures/gates
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }

        vector<int> dr = {-1, 1, 0, 0};
        vector<int> dc = {0, 0, -1, 1};

        while(!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for(int k = 0; k < 4; k++) {
                int r = x + dr[k];
                int c = y + dc[k];

                if(r >= 0 && r < m &&
                   c >= 0 && c < n &&
                   grid[r][c] == INF) {

                    grid[r][c] = grid[x][y] + 1;
                    q.push({r, c});
                }
            }
        }
    }
};