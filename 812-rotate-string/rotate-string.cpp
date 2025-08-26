class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()) return false;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            bool matchFlag = true;
            for (int j = 0; j < n; j++) {
                if (s[j] != goal[(i + j) % n]) {
                    matchFlag = false;
                    break;
                }
            }
            if (matchFlag) return true;
        }

        return false;
    }
};