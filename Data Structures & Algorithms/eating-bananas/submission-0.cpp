class Solution {
public:
bool func(vector<int> &piles,int mid,int h){
    int cnt=0;
    for(int i=0;i<piles.size();i++){
       cnt+=(piles[i]+mid-1)/mid;

    }
    return cnt<=h;
}
    int minEatingSpeed(vector<int>& piles, int h) {
       int ans=-1;
        int l=1;
        int hi=*max_element(piles.begin(),piles.end());
        while(l<=hi){
            int mid=l+(hi-l)/2;
            if(func(piles,mid,h)){
                ans=mid;
                hi=mid-1;

            }else{
                l=mid+1;
            }
        }
        return ans;
    }
};
