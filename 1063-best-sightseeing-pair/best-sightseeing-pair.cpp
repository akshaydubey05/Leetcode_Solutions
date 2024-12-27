class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& value)
    {
        int left=0;
        int ans=0;
        for(int i=1;i<value.size();i++)
        {
            ans=max(ans,value[i]+left+value[left]-i);
            left=value[left]+left<value[i]+i? i : left;
        }
        return ans;
    }
};