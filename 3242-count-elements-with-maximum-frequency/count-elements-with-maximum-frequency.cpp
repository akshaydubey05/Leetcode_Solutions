class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> m;
        for(auto i: nums){
            m[i]++;
        }
        int max=INT_MIN;
        for(auto i:m){
            if(max<i.second){
                max=i.second;
            }
        }
        int cnt=0;
        for(auto i:m){
            if(i.second==max){
                cnt+=max;
            }
        }
        return cnt;
    }
};