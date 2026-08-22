class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int j=0;
        int maxi=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(st.find(s[i])!=st.end()){
                while(st.find(s[i])!=st.end()){
                    st.erase(s[j]);
                    j++;
                }
            }
            st.insert(s[i]);
            maxi=max(maxi,i-j+1);
        }
        return maxi;
    }
};
