class Solution {
public:
    bool isPalindrome(string S)
    {
        // Stores the reverse of the
        // string S
        string P = S;
    
        // Reverse the string P
        reverse(P.begin(), P.end());
    
        // If S is equal to P
        if (S == P) {
            // Return "Yes"
            return true;
        }
        // Otherwise
        else {
            // return "No"
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