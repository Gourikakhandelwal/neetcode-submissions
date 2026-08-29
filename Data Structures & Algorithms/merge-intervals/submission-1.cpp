class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> v;
        sort(intervals.begin(),intervals.end());
        v.push_back({intervals[0][0],intervals[0][1]});
        for(auto it:intervals){
            if(v.back()[1]>=it[0]){
                vector<int> node=v.back();
                v.pop_back();
                v.push_back({node[0],max(node[1],it[1])});
            }else{
                v.push_back(it);
            }
        }
        return v;
    }
};
