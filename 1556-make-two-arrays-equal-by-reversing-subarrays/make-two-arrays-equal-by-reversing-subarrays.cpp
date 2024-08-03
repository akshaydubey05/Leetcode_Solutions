class Solution {
public:
    bool canBeEqual(vector<int>& t, vector<int>& a) {
        sort(t.begin(),t.end());
        sort(a.begin(),a.end());
        if(t==a){
            return true;
        }
        return false;
    }
};