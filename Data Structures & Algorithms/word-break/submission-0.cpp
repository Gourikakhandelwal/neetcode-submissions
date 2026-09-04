class Solution {
public:

    bool func(string s, vector<string>& wordDict, int index) {

        if (index >= s.size())
            return true;

        for (int j = index; j < s.size(); j++) {

            string temp = s.substr(index, j - index + 1);

            if (find(wordDict.begin(), wordDict.end(), temp) != wordDict.end()) {

                if (func(s, wordDict, j + 1))
                    return true;
            }
        }

        return false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
    
    int n = s.size();

    vector<bool> dp(n + 1, false);

    dp[n] = true;

    for (int i = n - 1; i >= 0; i--) {

        for (int j = i; j < n; j++) {

            string temp = s.substr(i, j - i + 1);

            if (find(wordDict.begin(), wordDict.end(), temp) != wordDict.end()) {

                if (dp[j + 1] == true) {
                    dp[i] = true;
                    break;
                }
            }
        }
    }

    return dp[0];
}
    
};
   