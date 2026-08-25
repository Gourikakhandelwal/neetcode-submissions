class Solution {
public:
bool palin(string &s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }
vector<vector<string>> res;
void func(int index,string s,vector<string> &v){
    if(index>=s.size()){
        res.push_back(v);
        return;
    }
    for(int i=index;i<s.size();i++){
        if(palin(s,index,i)){
            v.push_back(s.substr(index,i-index+1));
            func(i+1,s,v);
            v.pop_back();
        }
    }
   
}
    vector<vector<string>> partition(string s) {
        vector<string> v;
        func(0,s,v);
        return res;
    }
};
