class Solution {
public:
int func(int amount,vector<int>& coins,int index){
    if(index>=coins.size()){
        if(amount==0)return 1;
        return 0;
    }
    int pick=0;
    if(coins[index]<=amount){
        pick=func(amount-coins[index],coins,index);
    }
    int Notpick=func(amount,coins,index+1);
    return pick+Notpick;

}
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n+1,vector<int>(amount+1,0));
        for(int i=0;i<n;i++){
            dp[i][0]=1;
        }
        for(int i=n-1;i>=0;i--){
           for(int j=1;j<amount+1;j++){
            int pick=0;
                if(coins[i]<=j){
                    pick=dp[i][j-coins[i]];
                }
                dp[i][j]=pick+dp[i+1][j];
           }
        }
        return dp[0][amount];

    }
};
