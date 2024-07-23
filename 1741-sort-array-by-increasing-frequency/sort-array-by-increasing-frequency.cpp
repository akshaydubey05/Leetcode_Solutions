class Solution {
public:
    vector<int> frequencySort(vector<int>& n) {
        unordered_map<int,int> m;
        for(int i=0;i<n.size();i++){
            m[n[i]]++;
        }
        sort(n.begin(),n.end(), [&](auto a,auto b){
            if(m[a]!=m[b]){
                return m[a]<m[b];
            }
            return a>b;
        });
        return n;
    }
};