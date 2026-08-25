class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> count;
        vector<vector<int>> freq(nums.size()+1);
        for(auto num:nums){
            count[num]=1+count[num];
        }
        for(auto it:count){
            freq[it.second].push_back(it.first);
        }
        vector<int> res;
        for(int i=freq.size()-1;i>=0;i--){
            for(int j=0;j<freq[i].size();j++){
                res.push_back(freq[i][j]);
                if(res.size()==k){
                    return res;
                }
            }
        }
        return res;

    }
};
