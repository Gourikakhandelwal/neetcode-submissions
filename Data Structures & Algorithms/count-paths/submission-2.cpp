class Solution {
public:
int func(int m,int n,int i,int j){
    if(i<0||i>m||j<0||j>n)return 0;
    if(i==m-1 && j==n-1)return 1;
    int down=func(m,n,i+1,j);
    int right=func(m,n,i,j+1);
    return down+right;
}
    int uniquePaths(int m, int n) {

        vector<vector<int>> dp(m,vector<int>(n,0));
        dp[m-1][n-1]=1;
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(i==m-1 && j==n-1)continue;
                int down=(i>=m-1)?0:dp[i+1][j];
                int right=(j>=n-1)?0:dp[i][j+1];
                dp[i][j]=down +right;

            }
        }
        return dp[0][0];
    }
};
