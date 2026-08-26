class Solution {
public:
vector<string> v;
void func(int open,int close,string &temp,int n){
    if(open==0 && close==0){
        v.push_back(temp);
        return;
    }
    if(open>0){
        temp.push_back('(');
        func(open-1,close,temp,n);
        temp.pop_back();
    }
    if(close>open){
        temp.push_back(')');
        func(open,close-1,temp,n);
        temp.pop_back();
    }
}
    vector<string> generateParenthesis(int n) {
        string temp="";
        func(n,n,temp,n);
        return v;
    }
};
