class Solution {
public:
    int numWaterBottles(int full, int empty) {
        int ans=full;
        while(full>=empty){
            ans++;
            full=full-empty;
            full++;
        }
        return ans;
    }
};