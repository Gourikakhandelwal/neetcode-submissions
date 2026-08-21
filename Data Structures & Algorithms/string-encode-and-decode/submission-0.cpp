class Solution {
public:

    string encode(vector<string>& strs) {
        string str="";
        for(auto st:strs){
            str+=to_string(st.length());
            str+='#';
            str+=st;
        }
        return str;
    }

    vector<string> decode(string s) {
        int i=0;
        vector<string> result;
        while(i<s.length()){
            int len=0;
            while(s[i]!='#'){
                len=len*10+(s[i]-'0');
                i++;
            }
            i++;
            result.push_back(s.substr(i,len));
            i+=len;
        }
        return result;
    }
};
