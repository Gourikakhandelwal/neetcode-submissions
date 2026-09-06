class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        vector<vector<int>> visited(n,vector<int>(n,0));
        vector<pair<int, int>> dirs = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        pq.push({grid[0][0],0,0});
        visited[0][0]=grid[0][0];
        while(!pq.empty()){
            auto node=pq.top();
            pq.pop();
            int val=node[0];
            int x=node[1];
            int y=node[2];
              if (x == n - 1 && y == n - 1) return val;
               for (auto& dir : dirs) {
                int nr = x + dir.first;
                int nc = y + dir.second;
                if (nr >= 0 && nc >= 0 && nr < n && nc < n && !visited[nr][nc]) {
                    visited[nr][nc] = 1;
                    pq.push({max(val, grid[nr][nc]), nr, nc});
                }
            }
        }
        return -1;
    }

        
        
    
};
