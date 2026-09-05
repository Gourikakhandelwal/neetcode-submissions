class Solution {
public:

    int func(vector<vector<int>>& matrix, 
             vector<vector<int>>& dp,
             int i, int j) {

        if(dp[i][j] != -1)
            return dp[i][j];

        int ans = 1;

        if(i > 0 && matrix[i-1][j] > matrix[i][j])
            ans = max(ans, 1 + func(matrix, dp, i-1, j));

        if(i < matrix.size()-1 && matrix[i+1][j] > matrix[i][j])
            ans = max(ans, 1 + func(matrix, dp, i+1, j));

        if(j > 0 && matrix[i][j-1] > matrix[i][j])
            ans = max(ans, 1 + func(matrix, dp, i, j-1));

        if(j < matrix[0].size()-1 && matrix[i][j+1] > matrix[i][j])
            ans = max(ans, 1 + func(matrix, dp, i, j+1));

        return dp[i][j] = ans;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {

        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        int maxi = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                maxi = max(maxi, func(matrix, dp, i, j));
            }
        }

        return maxi;
    }
};