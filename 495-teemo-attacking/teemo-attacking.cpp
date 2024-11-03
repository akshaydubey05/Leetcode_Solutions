class Solution {
public:
    int findPoisonedDuration(vector<int>& t, int duration) {
        int i = 0, j = 1, ans = 0;
        while(j < t.size()){
            if(t[j] <= t[i] + duration){
                ans += (t[j]-t[i]);
            }
            else{
                ans += duration;
            }
            i = j;
            j++;
        }
        ans += duration;
        return ans;
    }
};