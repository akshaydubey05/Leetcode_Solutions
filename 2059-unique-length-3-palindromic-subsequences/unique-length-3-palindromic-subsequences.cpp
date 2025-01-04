class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int res = 0;
        unordered_set<char> st(s.begin(), s.end());
        for(auto i : st){
            cout<<i<<" ";
        }
        
        for (char c : st) {
            int start = -1, end = 0;
            for (int i = 0; i < s.size(); i++) {
                if (s[i] == c) {
                    if (start == -1) start = i;
                    end = i;
                }
            }
            unordered_set<char> st1;
            for (int i = start + 1; i < end; i++) {
                st1.insert(s[i]);
            }
            res += st1.size();
        }
        return res;
    }
};
