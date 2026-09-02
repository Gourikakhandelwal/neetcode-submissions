class Solution {
public:
    int func(vector<int>& coins, int amount, int index) {

        if (amount == 0)
            return 0;

        if (index >= coins.size())
            return INT_MAX;

        int pick = INT_MAX;

        if (amount >= coins[index]) {
            int x = func(coins, amount - coins[index], index);

            if (x != INT_MAX)
                pick = 1 + x;
        }

        int Notpick = func(coins, amount, index + 1);

        return min(pick, Notpick);
    }

    int coinChange(vector<int>& coins, int amount) {
         int n = coins.size();

        vector<vector<int>> dp(n, vector<int>(amount + 1, INT_MAX));

        // Amount = 0 requires 0 coins
        for (int i = 0; i < n; i++) {
            dp[i][0] = 0;
        }

        // Using only coins[0]
        for (int j = 1; j <= amount; j++) {
            if (j >= coins[0] && dp[0][j - coins[0]] != INT_MAX) {
                dp[0][j] = 1 + dp[0][j - coins[0]];
            }
        }

        for (int i = 1; i < n; i++) {

            for (int j = 1; j <= amount; j++) {

                // Not pick
                dp[i][j] = dp[i - 1][j];

                // Pick
                if (coins[i] <= j && dp[i][j - coins[i]] != INT_MAX) {
                    dp[i][j] = min(
                        dp[i][j],
                        1 + dp[i][j - coins[i]]
                    );
                }
            }
        }

        if (dp[n - 1][amount] == INT_MAX)
            return -1;

        return dp[n - 1][amount];
    }
};