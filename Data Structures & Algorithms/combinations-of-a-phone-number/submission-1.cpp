class Solution {
public:
vector<string> res;
void func(int index,string &digits,unordered_map<char,string> &mp,string &temp){
    if(index==digits.size()){
        res.push_back(temp);
        return;
    }
    for(int i=0;i<mp[digits[index]].size();i++){
        temp.push_back(mp[digits[index]][i]);
        func(index+1,digits,mp,temp);
        temp.pop_back();
    }
}
    vector<string> letterCombinations(string digits) {
        unordered_map<char,string> mp;
        if(digits.size()==0)return res;
        mp['2']="abc";
        mp['3']="def";
        mp['4']="ghi";
        mp['5']="jkl";
        mp['6']="mno";
        mp['7']="pqrs";
        mp['8']="tuv";
        mp['9']="wxyz";
        string temp="";
        func(0,digits,mp,temp);
        return res;
    }
};
