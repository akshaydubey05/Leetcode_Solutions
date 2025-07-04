class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size()-1;
        unordered_set<int> s;
        for(auto i: nums){
            s.insert(i);
        }
        if(n+1==0){
            return 0;
        }
        int maxi = INT_MIN;
        for(auto i:s){
            if(s.find(i-1)==s.end()){
                int cnt =0;
                cnt++;
                while(s.find(i+1)!=s.end()){
                    cnt++;
                    i++;
                }
                maxi=max(maxi, cnt);
            }
        }
        return maxi;
    }
};