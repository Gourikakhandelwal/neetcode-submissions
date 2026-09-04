class Solution {
public:
int func(string word1, string word2, int i, int j) {

    if(i >= word1.size())
        return word2.size() - j;

    if(j >= word2.size())
        return word1.size() - i;

    if(word1[i] == word2[j]) {
        return func(word1, word2, i+1, j+1);
    }

    return 1 + min({
        func(word1, word2, i, j+1),    
        func(word1, word2, i+1, j),     
        func(word1, word2, i+1, j+1)    
    });
}
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for(int j = 0; j <= m; j++) {
            dp[n][j] = m - j;
        }

        for(int i = 0; i <= n; i++) {
            dp[i][m] = n - i;
        }

        for(int i = n - 1; i >= 0; i--) {
            for(int j = m - 1; j >= 0; j--) {

                if(word1[i] == word2[j]) {

                    dp[i][j] = dp[i+1][j+1];

                }
                else {

                    int insert = dp[i][j+1];
                    int deletee = dp[i+1][j];
                    int replace = dp[i+1][j+1];

                    dp[i][j] = 1 + min({
                        insert,
                        deletee,
                        replace
                    });
                }
            }
        }

        return dp[0][0];
    }
};
        
    