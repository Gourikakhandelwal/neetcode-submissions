class Solution {
public:
vector<vector<int>> v;

void func(int index,vector<int>& nums,vector<int> &temp,unordered_map<int,int> &mp){
    if(temp.size()==nums.size()){
        v.push_back(temp);
        return;
    }
    for(int i=0;i<nums.size();i++){
        if(mp.find(nums[i])==mp.end()){
            mp[nums[i]]++;
        temp.push_back(nums[i]);
      
        func(index+1,nums,temp,mp);
        temp.pop_back();
        mp.erase(nums[i]);
        }
    }
}
    vector<vector<int>> permute(vector<int>& nums) {
        unordered_map<int,int> mp;
        vector<int> temp;
        func(0,nums,temp,mp);
        return v;
    }
};
