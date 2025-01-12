class Solution {
public:
    bool canBeValid(string s, string locked) {
        // If the string length is odd, it can never be balanced
        if (s.size() % 2 != 0)
            return false;

        int wildCard = 0;  // To count unlocked characters (?)
        int open = 0;      // To count open brackets '('
        int close = 0;     // To count close brackets ')'

        // Left-to-right pass
        for (int i = 0; i < s.size(); i++) {
            if (locked[i] == '0')
                wildCard++;  // Unlocked character
            else if (s[i] == '(' && locked[i] == '1')
                open++;  // Open parenthesis
            else if (s[i] == ')' && locked[i] == '1')
                close++;  // Close parenthesis

            // If closing parentheses exceed opening, check if wildcards can balance it
            if (close > open && close - open > wildCard)
                return false;
        }

        // Reset variables for the right-to-left pass
        wildCard = 0;
        open = 0;
        close = 0;

        // Right-to-left pass
        for (int i = s.size() - 1; i >= 0; i--) {
            if (locked[i] == '0')
                wildCard++;  // Unlocked character
            else if (s[i] == '(' && locked[i] == '1')
                open++;  // Open parenthesis
            else if (s[i] == ')' && locked[i] == '1')
                close++;  // Close parenthesis

            // If opening parentheses exceed closing, check if wildcards can balance it
            if (open > close && open - close > wildCard)
                return false;
        }

        return true;
    }
};
