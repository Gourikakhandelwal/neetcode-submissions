class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       unordered_set<int> st(nums.begin(),nums.end());
       int maxi=0;
       for(int i=0;i<nums.size();i++){
        if(st.find(nums[i]-1)==st.end()){
        int length=1;
        while(st.find(nums[i]+length)!=st.end()){
            length++;
        }
        maxi=max(maxi,length);
       }
       }
       return maxi;
    }
};
