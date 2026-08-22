class MinStack {
public:
long long mini;
stack<long long> st;
    MinStack() {
         mini=LLONG_MAX;
    }
    
    void push(int val) {
        if(st.empty()){
            st.push(val);
            mini=val;
        }else if(val<mini){
            st.push(2LL*val-mini);
            mini=val;
        }else{
            st.push(val);
        }
        

    }
    
    void pop() {
       long long x=st.top();
       st.pop();
       if(x<mini){
        mini=2*mini-x;
       }

    }
    
    int top() {
        long long x=st.top();
        
        if(x<mini){
            return mini;
        }
        return x;
    }
    
    int getMin() {
        return mini;
    }
};
