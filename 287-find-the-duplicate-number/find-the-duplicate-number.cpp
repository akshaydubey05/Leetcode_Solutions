#define faster                 \
  ios::sync_with_stdio(false); \
  cin.tie(nullptr);            \
  cout.tie(nullptr);

class Solution {
public:
    int findDuplicate(vector<int>& n) {
        faster
        unordered_map<int,int> m;
        for(auto i:n){
            m[i]++;
        }
        for(auto i:m){
            if(i.second>1){
                return i.first;
            }
        }
        return -1;
    }
};