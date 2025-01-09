class Solution {
public:
    int distributeCandies(vector<int>& ct) {
        set<int> s(ct.begin(),ct.end());
        if(s.size()>ct.size()/2){
            return ct.size()/2;
        }
        return s.size();
    }
};