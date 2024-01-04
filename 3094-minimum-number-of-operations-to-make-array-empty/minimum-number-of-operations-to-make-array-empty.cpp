class Solution {
public:
    int minOperations(vector<int>& nums) {
        //sort(nums.begin(),nums.end());
        unordered_map<int,int> m;
        for(auto i:nums){
            m[i]++;
        }
        int ans=0;
        for(auto i:m){
            if(i.second==1){
                return -1;
            }
            if(i.second%3==0){
                ans=ans+i.second/3;
            }
            else{
                ans+=(i.second/3)+1;
            }
        }
        return ans;
    }
};