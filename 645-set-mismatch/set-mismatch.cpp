class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> a;
        int n=nums.size();
        int b=0;
        sort(nums.begin(),nums.end());
        for(auto &i:nums){
            if(i==*(&i+1)){
                b=i;
                a.push_back(i);
                break;
            }
        }
        int sum=0;
        for(auto i:nums){
            sum+=i;
        }
        int c=n*(n+1)/2;
        int d=sum-b;
        a.push_back(c-d);

        return a;
    }
};