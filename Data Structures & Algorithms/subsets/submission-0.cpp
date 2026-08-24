class Solution {
public:
void func(int index,vector<int> &temp,vector<vector<int>> &res,vector<int> & nums){
    if(index>=nums.size()){
        res.push_back(temp);
        return;
    }
    temp.push_back(nums[index]);
    func(index+1,temp,res,nums);
    temp.pop_back();
    func(index+1,temp,res,nums);
}
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        func(0,temp,res,nums);
        return res;
    }
};
