class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> s1_freq;
        unordered_map<char,int> s2_freq;
        if(s1.length()>s2.length())return false;
        for(char c:s1){
            s1_freq[c]++;
        }
        int l=0;
        for(int r=0;r<s2.length();r++){
            s2_freq[s2[r]]++;
            if(r-l+1>s1.length()){
                if(--s2_freq[s2[l]] == 0) s2_freq.erase(s2[l]);
                l++;
            }
            if(s2_freq==s1_freq){
                return true;
            }
        }
        return false;
    }
};
