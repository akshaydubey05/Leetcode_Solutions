class Solution {
public:
    bool isPalindrome(string S)
    {
        string P = S;
        reverse(P.begin(), P.end());
        if (S == P) {
            return true;
        }
        else {
            return false;
        }
    }
    int countSubstrings(string s) {
        int count = 0;
        int n = s.length();
        for (int i = 0; i < n; i++){ 
            for (int len = 1; len <= n - i; len++){
                string k = s.substr(i, len);
                if(isPalindrome(k)){
                    count++;
                }
            }
        }      
        return count;
    }
};