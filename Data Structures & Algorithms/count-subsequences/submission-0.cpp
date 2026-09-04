class Solution {
public:
int func(string s,string t,int i,int j){
    if(j>=t.size())return 1;
    if(i>=s.size())return 0;
    int take=0;
    if(s[i]==t[j]){
        take=func(s,t,i+1,j+1);
    }
    int notTake=func(s,t,i+1,j);
    return take+notTake;
    
}
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<=n;i++){
        dp[i][m]=1;
        }
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(s[i]==t[j]){
                    dp[i][j]=dp[i+1][j+1];
                }
                dp[i][j]+=dp[i+1][j];
            }
        }
    return dp[0][0];
    }
};
