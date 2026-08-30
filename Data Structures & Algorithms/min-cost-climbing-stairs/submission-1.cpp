class Solution {
public:
int func(int index,vector<int> &cost){
    if(index>=cost.size()){
        return 0;
    }
    return cost[index]+min(func(index+1,cost),func(index+2,cost));
}
    int minCostClimbingStairs(vector<int>& cost) {
       
        int n=cost.size();
        vector<int> dp(n+1);
        for(int i=2;i<=n;i++){
            dp[i] = min(dp[i - 1] + cost[i - 1],
                        dp[i - 2] + cost[i - 2]);
        }

        return dp[n];
        }

    
};
