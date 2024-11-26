class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        
        vector<bool> track(n,true);

        for(auto& it : edges)
        {
            track[it[1]] = false;
        }

        int count=0;
        int ans;
        for(int i=0; i<n; i++)
        {
            if(track[i]==true)
            {
                if(++count >1) return -1;
                ans=i;
            }
        }
        return ans;
    }
};