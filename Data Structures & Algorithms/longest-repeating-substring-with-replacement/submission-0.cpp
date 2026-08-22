class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> mp;
        int l=0;
        int maxi=0;
        int maxf=0;
        int n=s.size();
        for(int r=0;r<n;r++){
            mp[s[r]]++;
            maxf=max(maxf,mp[s[r]]);
            while((r-l+1)-maxf>k){
                mp[s[l]]--;
                l++;
            }
            maxi=max(maxi,(r-l+1));
        }
        return maxi;
    }
};
