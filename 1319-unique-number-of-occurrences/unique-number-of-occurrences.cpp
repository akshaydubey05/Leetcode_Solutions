class Solution {
public:
    bool uniqueOccurrences(vector<int>& a) {
        unordered_map<int,int> m;
        vector<int> v;
        for(auto i:a){
            m[i]++;
        }
        for(auto i:m){
            v.push_back(i.second);
        }
        set<int> s(v.begin(),v.end());
        if(s.size()!=v.size()){
            return false;
        }
        else{
            return true;
        }
    }
};