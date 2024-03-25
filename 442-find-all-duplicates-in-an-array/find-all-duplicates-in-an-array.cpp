class Solution {
public:
    vector<int> findDuplicates(vector<int>& n) {
        vector<int> a;
        unordered_map<int,int> m;
        for(auto i:n){
            m[i]++;
        }
        for(auto i:m){
            if(i.second>1){
                a.push_back(i.first);
            }
        }
        return a;

        
    }
};