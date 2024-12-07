class Solution {
public:
    bool solve(int mid, vector<int>& nums, int maxOperations){
        int cnt=0;

        for(int i=0;i<nums.size();i++){
            int balls=nums[i];
            if(balls<=mid)continue;

            if(balls%mid==0){
                cnt+=((balls/mid)-1);
            }
            else{
                cnt+=(balls/mid);
            }
            if(cnt>maxOperations){
                return false;
            }
        }
        return true;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int n=nums.size();
        int ans=0;
        int i=1,j=*max_element(nums.begin(),nums.end());

        while(i<=j){
            int mid=(i+j)/2;

            if(solve(mid,nums,maxOperations)==true){
                ans=mid;
                j=mid-1;
            }
            else{
                i=mid+1;
            }
        }
        return ans;
    }
};