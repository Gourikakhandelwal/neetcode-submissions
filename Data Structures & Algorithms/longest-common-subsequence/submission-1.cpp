class Solution {
public:
int func(string text1,string text2,int i,int j){
    if(i>=text1.size()||j>=text2.size())return 0;
    if(text1[i]==text2[j]){
        return 1+func(text1,text2,i+1,j+1);
    }else{
        return max(func(text1,text2,i+1,j),func(text1,text2,i,j+1));
    }

}
    int longestCommonSubsequence(string text1, string text2) {

        vector<vector<int>> dp(text1.size()+1,vector<int>(text2.size()+1,0));
        for(int i=text1.size()-1;i>=0;i--){
            for(int j=text2.size()-1;j>=0;j--){
                if(text1[i]==text2[j]){
                    dp[i][j]=1+dp[i+1][j+1];
                }else{
                    dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
                }
            }
        }
        return dp[0][0];
    }
};
