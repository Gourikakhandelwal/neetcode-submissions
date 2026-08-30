class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> v;
        intervals.push_back({newInterval});
        sort(intervals.begin(),intervals.end());
        v.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++){
            if(v.back()[1]>=intervals[i][0]){
                vector<int> node=v.back();
                v.pop_back();
                v.push_back({node[0],max(node[1],intervals[i][1])});
            }
            else{
                v.push_back(intervals[i]);
            }
        }
        return v;
    }
};
