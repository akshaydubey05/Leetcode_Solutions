class Solution {
public:
    pair<int,int> solve(vector<int> &freq)
    {
        int mx=INT_MIN;
        int mn=INT_MAX;

        for(int i=0;i<26;i++)
        {
            if(freq[i]!=0)
            {
                mx=max(mx,freq[i]);
                mn=min(mn,freq[i]);
            }
        }
        return {mx,mn};
    }
    int beautySum(string s) {
        int n=s.length();
        int ans=0;

        for(int i=0;i<n;i++)
        {
            vector<int> freq(26,0);
            for(int j=i;j<n;j++)
            {
                freq[s[j]-'a']++;
                auto curr=solve(freq);
                ans+=(curr.first-curr.second);
            }
        }
        return ans;
    }
};