class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int ans = 0, places = 24;
        while(places--) {
            int setBits = 0;
            for(auto &i:candidates) {
                setBits += i&1;
                i>>=1;
            }
            ans = max(ans, setBits);
        }
        return ans;
    }
};