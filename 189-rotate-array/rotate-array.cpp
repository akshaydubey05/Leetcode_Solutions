class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> a;
        int n = nums.size();
        if(k>n){
            k=k%n;
        }
        int x=0, i=n-k;
        while(x<n){
            if(i>n-1){
                i=0;
            }
            a.push_back(nums[i]);
            i++;
            x++;
        }
        nums=a;
    }
};