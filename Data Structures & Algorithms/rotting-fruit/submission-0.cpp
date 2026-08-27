class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<int> row={-1,1,0,0};
        vector<int> col={0,0,-1,1};
        int cnt=0;
        int dist=0;
        queue<pair<int,pair<int,int>>> q;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2){
                    q.push({0,{i,j}});
                }
                else if(grid[i][j]==1)cnt++;
            }
        }
        int ct=0;
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            int x=node.second.first;
            int y=node.second.second;
            int d=node.first;
            dist=max(dist,d);
            for(int k=0;k<4;k++){
                int r=row[k]+x;
                int c=col[k]+y;
                if(r>=0 && r<grid.size() && c>=0 && c<grid[0].size() && grid[r][c]==1){
                    ct++;
                    grid[r][c]=2;
                   
                    q.push({d+1,{r,c}});

                }
            }
        }
        if(ct!=cnt){
            return -1;
        }
        return dist;
    }
};
