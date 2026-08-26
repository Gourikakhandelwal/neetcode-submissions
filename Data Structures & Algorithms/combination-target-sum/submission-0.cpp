class Solution {
public:
vector<vector<int>> res;
void func(int index,vector<int> &nums,vector<int> &temp,int target){
    if(target==0){
        res.push_back(temp);
        return;
    }
    if(index>=nums.size())return;
    if(target>=nums[index]){
        temp.push_back(nums[index]);
        func(index,nums,temp,target-nums[index]);
        temp.pop_back();
    }
    func(index+1,nums,temp,target);
    
}
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> temp;
        func(0,nums,temp,target);
        return res;
    }
};
