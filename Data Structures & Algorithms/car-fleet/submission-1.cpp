class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<int> res;
        int n=speed.size();
        vector<pair<int,double>> v;
        for(int i=0;i<speed.size();i++){
            v.push_back({position[i],(double)(target-position[i])/speed[i]});
        }
        sort(v.begin(),v.end());
        stack<double> st;
        for(int i=n-1;i>=0;i--){
            if(!st.empty() && v[i].second<=st.top()){
                continue;
            }
            st.push(v[i].second);

        }
        return st.size();

    }
};
