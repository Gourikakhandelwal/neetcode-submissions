class Solution {
public:
bool isNum(char c){
    if((c>='A' && c<='Z')||(c>='a' && c<='z')||(c>='0' && c<='9'))return true;
    return false;
}
    bool isPalindrome(string s) {
        int i=0;
        int j=s.length()-1;
        while(i<j){
            while(i<j && !isNum(s[i])){
                i++;
            }
            while(i<j && !isNum(s[j])){
                j--;
            }
            if(tolower(s[i])!=tolower(s[j])){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};
