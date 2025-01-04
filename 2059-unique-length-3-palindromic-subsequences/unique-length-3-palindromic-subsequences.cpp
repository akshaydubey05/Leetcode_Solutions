class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int res = 0;
        unordered_set<char> uniqueChars(s.begin(), s.end());
        for (char c : uniqueChars) {
            int start = -1, end = 0;
            for (int i = 0; i < s.size(); i++) {
                if (s[i] == c) {
                    if (start == -1) start = i;
                    end = i;
                }
            }
            unordered_set<char> midChars;
            for (int i = start + 1; i < end; i++) {
                midChars.insert(s[i]);
            }
            res += midChars.size();
        }
        return res;
    }
};
