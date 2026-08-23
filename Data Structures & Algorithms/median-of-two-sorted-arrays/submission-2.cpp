class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        if(n>m){
            return findMedianSortedArrays(nums2,nums1);
        }
        int l=0;
        int h=nums1.size();
        while(l<=h){
            int l1=l+(h-l)/2;
            int l2=(n+m+1)/2-l1;
            int max1=(l1==0)?INT_MIN:nums1[l1-1];
            int min1=(l1==n)?INT_MAX:nums1[l1];
            int max2=(l2==0)?INT_MIN:nums2[l2-1];
            int min2=(l2==m)?INT_MAX:nums2[l2];
            if(max1<=min2 && max2<=min1){
                if((n+m)%2==0){
                    return (double)(max(max1,max2)+min(min1,min2))/2.0;
                }else{
                    return (double)max(max1,max2);
                }
            }else if(max1>min2){
                h=l1-1;
            }else{
                l=l1+1;
            }
        }

        return -1;
    }
};
