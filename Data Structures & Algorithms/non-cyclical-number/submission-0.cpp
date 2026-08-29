class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> st;
        while(n!=1){
            int sum=0;
        while(n>0){
            int square=n%10;
            sum=sum+(square*square);
            n=n/10;
        }
        if(st.count(sum))return false;
        st.insert(sum);
        n=sum;
    }
    return true;
    }
};
