class Solution {
public:
    string minWindow(string s, string t) {
        if(s==t)return s;
   
        unordered_map<char,int> mp;
        for(char c:t){
            mp[c]++;
        }
        int start=-1;
        int minLen=INT_MAX;
        int need=0;
        int l=0;
        for(int r=0;r<s.length();r++){
            if(mp[s[r]]>0){
                need++;
            }
            mp[s[r]]--;
            while(need==t.size()){
                if(r-l+1<minLen){
                    minLen=r-l+1;
                    start=l;
                }
                    mp[s[l]]++;
                    
                    if(mp[s[l]]>0)need--;
                    l++;
                }

            }
            return start==-1?"":s.substr(start,minLen);


        }
    
};
