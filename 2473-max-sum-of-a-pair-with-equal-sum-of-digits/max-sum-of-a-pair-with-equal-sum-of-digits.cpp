class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int,priority_queue<int>> m;

        for(auto n : nums){
            int sum = 0,temp = n;
            while(temp != 0){
                sum+=(temp%10);
                temp/=10;
            }
            m[sum].push(n);
        }

        int maxi = -1;

        for(auto [key,value] : m){
            if(value.size() >= 2){
                int first = value.top();
                value.pop();
                int second = value.top();
                int maxOfEqualSum = first + second;
                maxi = max(maxi,maxOfEqualSum);
            }            
        }

        return maxi;
    }
};