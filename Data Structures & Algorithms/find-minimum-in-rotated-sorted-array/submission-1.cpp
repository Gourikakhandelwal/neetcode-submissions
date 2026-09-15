class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        int ans = nums[0];

        while(l <= r) {

            // Current range is sorted
            if(nums[l] <= nums[r]) {
                ans = min(ans, nums[l]);
                break;
            }

            int mid = l + (r - l) / 2;

            ans = min(ans, nums[mid]);

            if(nums[mid] >= nums[l]) {
                // Left half is sorted
                l = mid + 1;
            }
            else {
                // Minimum is in left half
                r = mid - 1;
            }
        }

        return ans;
    }
};