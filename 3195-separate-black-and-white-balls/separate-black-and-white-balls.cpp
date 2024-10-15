class Solution {
public:
    long long minimumSteps(string s) {
        int whitePos = 0;
        long ans = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '0') {
                ans += (i - whitePos);
                whitePos++;
            }
        }
        return ans;
    }
};