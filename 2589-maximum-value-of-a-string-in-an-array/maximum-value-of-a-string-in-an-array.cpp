class Solution {
public:
    int maximumValue(vector<string>& str) 
    {
        int ans = INT_MIN;
        for(auto it:str)
        {
            bool flag = true;
            int n = it.size();
            for(char ch:it)
            {
                if(isalpha(ch))
                {
                    ans = max(ans, n);
                    flag = false;
                    break;
                }
            }
            if(flag) ans = max(ans, stoi(it));
        }
        return ans;
    }
};
