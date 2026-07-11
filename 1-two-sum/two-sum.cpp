class Solution {
public:
    vector<int> twoSum(vector<int>& n, int t) {
        map<int,int> mp;
        for(int i=0;i<n.size();i++){
            int cnt=t-n[i];
            if(mp.find(cnt)!=mp.end()){
                return {mp[cnt],i};
            }
            mp[n[i]]=i;
        }
        return {-1,-1};
    }
};