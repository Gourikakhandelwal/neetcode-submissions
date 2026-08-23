class Solution {
public:
    int findMin(vector<int> &nums) {
        int ans=nums[0];
        int l=0;
        int h=nums.size()-1;
        while(l<=h){
           
            if(nums[l]<nums[h]){
                ans=min(ans,nums[l]);
                break;
            }
            int mid=l+(h-l)/2;
            ans=min(ans,nums[mid]);
            if(nums[mid]>=nums[l]){
                l=mid+1;
            }else{
                h=mid-1;
            }
        }
        return ans;
    }
};
