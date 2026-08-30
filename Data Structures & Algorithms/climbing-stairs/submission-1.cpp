class Solution {
public:
int func(int n){
    if(n==0){
        return 1;
    }
    int first=(n>=1)?func(n-1):0;
    int second=(n>=2)?func(n-2):0;
    return first+second;
}
    int climbStairs(int n) {
        vector<int> dp(n+1,0);
        dp[0]=1;
        for(int i=1;i<=n;i++){
            int first=(i>=1)?dp[i-1]:0;
            int second=(i>=2)?dp[i-2]:0;
            dp[i]=first+second;
        }
        return dp[n];
    }
};
