class Solution {
public:
set<vector<int>> v;
void func(int i,vector<int>& nums,vector<int> &temp){
    if(i==nums.size()){
        v.insert(temp);
        return ;
    }
    
        temp.push_back(nums[i]);
        func(i+1,nums,temp);
       
    
    temp.pop_back();
    
    func(i+1,nums,temp);
    
    
}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> temp;
        func(0,nums,temp);
        return vector<vector<int>> (v.begin(),v.end());
    }
};
