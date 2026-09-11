class Solution {
public:
int func(int n){
    int res=0;
    while(n>0){
        res=res+((n%10)*(n%10));
        n=n/10;
    }
    return res;
}
    bool isHappy(int n) {
        int slow=n;
        int fast=func(n);
        while(fast!=slow){
            slow=func(slow);
            fast=func(fast);
            fast=func(fast);
        }
        return fast==1;
    }
};
