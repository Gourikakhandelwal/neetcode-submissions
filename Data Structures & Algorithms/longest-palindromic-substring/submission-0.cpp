class Solution {
public:
    string longestPalindrome(string s) {
        int start=0;
        int maxi=0;
        for(int centre=0;centre<s.length();centre++){
            int l=centre;
            int r=centre;
            while(l>=0 && r<s.size() && s[l]==s[r]){
                
                if(r-l+1>maxi){
                    maxi=max(r-l+1,maxi);
                    start=l;
                }
                l--;
                r++;
            }
             l = centre;
            r = centre + 1;

            while (l >= 0 && r < s.size() && s[l] == s[r]) {
                if (r - l + 1 > maxi) {
                    start = l;
                    maxi = r - l + 1;
                }

                l--;
                r++;
            }
        }

        return s.substr(start, maxi);

        }
    
};
