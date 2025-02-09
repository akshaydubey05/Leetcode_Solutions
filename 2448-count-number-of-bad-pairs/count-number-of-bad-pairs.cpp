class Solution {
public:
    long long countBadPairs(vector<int>& n) {
        unordered_map<int,int> mp;
        long long int x=0;
        for(int i=0;i<n.size();i++){
            if(mp.find(n[i]-i)!=mp.end()){
                x+=mp[n[i]-i];
            }
            mp[n[i]-i]++;
        }
        return (n.size()*(n.size()-1))/2 - x;
    }
};