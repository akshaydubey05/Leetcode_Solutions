class Solution {
public:
    bool isVowel(char ch)
    {
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch== 'o' || ch == 'u');
    }

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        
        int n = words.size();
        int m = queries.size();

        vector<int>prefix(n,0);
        vector<int>result(m,0);

        for(int i=0;i<words.size();i++)
        {
            int isVowelAtEnds = isVowel(words[i][0]) && isVowel(words[i][words[i].size()-1] );
            prefix[i] += (i==0)?isVowelAtEnds: isVowelAtEnds+prefix[i-1];
        }
        
        for(int i=0;i<queries.size();i++)
        {
            int start = queries[i][0];
            int end = queries[i][1];

            result[i] =(start==0)? prefix[end] : prefix[end] - prefix[start-1];
        }

        return result;
    }
};