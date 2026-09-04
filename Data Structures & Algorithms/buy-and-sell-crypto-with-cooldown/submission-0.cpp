class Solution {
public:
int func(vector<int>& prices,int i,int buy){
    if(i>=prices.size()){
        return 0;
    }
    int profit1=0;
    int profit0=0;
    if(buy==0){
        int pick=-prices[i]+func(prices,i+1,1);
        int notpick=func(prices,i+1,0);
        return profit1=max(pick,notpick);
    }
    
    else{
        int pick=prices[i]+func(prices,i+2,0);
        int notpick=func(prices,i+1,1);
        return profit0=max(pick,notpick);
    }
    

}
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n+2,vector<int>(2,0));
        
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<2;j++){
                if(j==0){
                    dp[i][j]=max(-prices[i]+dp[i+1][1],dp[i+1][0]);
                }
                if(j==1){
                    dp[i][j]=max(prices[i]+dp[i+2][0],dp[i+1][1]);
                }
            }
        }
        return dp[0][0];
    }
};
