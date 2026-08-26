class Solution {
public:
    vector<vector<int>> res;

    void func(int index, vector<int>& nums, vector<int>& temp, int target) {
        if (target == 0) {
            res.push_back(temp);
            return;
        }

        for (int i = index; i < nums.size(); i++) {
            if (i > index && nums[i] == nums[i - 1])
                continue;

            if (nums[i] > target)
                break;

            temp.push_back(nums[i]);
            func(i + 1, nums, temp, target - nums[i]);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<int> temp;
        func(0, candidates, temp, target);

        return res;
    }
};