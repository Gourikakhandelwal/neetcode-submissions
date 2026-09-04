class Solution {
public:
int func(vector<int>& nums,int target){
    int n=nums.size();
    vector<vector<int>> dp(n,vector<int>(target+1,0));
    for(int i=0;i<n;i++){
        dp[i][0]=1;
    }
    dp[0][nums[0]]=1;
    for(int i=1;i<n;i++){
        for(int j=1;j<target+1;j++){
            int pick=0;
            if(nums[i]<=j){
                pick=dp[i-1][j-nums[i]];
            }
            int Notpick=dp[i-1][j];
            dp[i][j]=pick||Notpick;
        }
    }
    return dp[n-1][target];
}
    bool canPartition(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%2!=0)return false;
        int d=sum/2;
        return func(nums,d);
        
    }
};
