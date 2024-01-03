class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> final(nums1.size()+nums2.size());
        merge(nums1.begin(),nums1.end(),nums2.begin(),nums2.end(),final.begin());
        int n=final.size();
        if(n%2!=0){
            int mid=(n-1)/2;
            double ans=final[mid]*1.0;
            return ans;
        }
        else{
            int x=n/2;
            int y=n/2-1;
            double ans=(final[x]+final[y])/2.0;
            return ans;
        }
        //return 0;
    }
};