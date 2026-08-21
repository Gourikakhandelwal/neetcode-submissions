class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> count;
        for(auto s:strs){
            vector<int> freq(26,0);
            for(int i=0;i<s.size();i++){
                freq[s[i]-'a']++;
            }
            string key=to_string(freq[0]);
            for(int i=0;i<26;i++){
                key+=',' +to_string(freq[i]);
            }
            count[key].push_back(s);


        }
        vector<vector<string>> v;
        for(const auto &str:count){
            v.push_back(str.second);
        }
        return v;
    }
};
