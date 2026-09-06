class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        int n = nums.size();

        vector<int> left(n);
        vector<int> right(n);

        left[0] = nums[0];
        right[n - 1] = nums[n - 1];

        for (int i = 1; i < n; i++) {

            // LEFT array
            if (i % k == 0) {
                left[i] = nums[i];
            } 
            else {
                left[i] = max(left[i - 1], nums[i]);
            }

            // RIGHT array
            int idx = n - i - 1;

            if (idx % k == 0) {
                right[idx] = nums[idx];   
            } 
            else {
                right[idx] = max(right[idx + 1], nums[idx]);
            }
        }

        vector<int> output(n - k + 1);

        for (int i = 0; i < n - k + 1; i++) {
            output[i] = max(left[i + k - 1], right[i]);
        }

        return output;
    }
};