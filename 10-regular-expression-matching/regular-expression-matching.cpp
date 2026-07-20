class Solution {
public:
    bool isMatch(string s, string p) {
        int stringLength = s.length();
        int patternLength = p.length();
        
        // Initialize memoization table with -1 (unvisited)
        vector<vector<int>> memo(stringLength + 1, vector<int>(patternLength + 1, -1));
        return checkMatch(0, 0, s, p, memo);
    }

private:
    bool checkMatch(int stringIndex, int patternIndex, const string& s, const string& p, vector<vector<int>>& memo) {
        // Base case: if pattern is fully consumed
        if (patternIndex == p.length()) {
            return stringIndex == s.length();
        }

        // Return cached result if already computed
        if (memo[stringIndex][patternIndex] != -1) {
            return memo[stringIndex][patternIndex];
        }

        // Check if the current characters match
        bool firstMatch = (stringIndex < s.length() && 
                          (s[stringIndex] == p[patternIndex] || p[patternIndex] == '.'));

        bool result = false;
        
        // If the next character is '*'
        if (patternIndex + 1 < p.length() && p[patternIndex + 1] == '*') {
            result = checkMatch(stringIndex, patternIndex + 2, s, p, memo) || 
                     (firstMatch && checkMatch(stringIndex + 1, patternIndex, s, p, memo));
        } else {
            // Normal matching step
            result = firstMatch && checkMatch(stringIndex + 1, patternIndex + 1, s, p, memo);
        }

        // Cache and return the result
        return memo[stringIndex][patternIndex] = result;
    }
};