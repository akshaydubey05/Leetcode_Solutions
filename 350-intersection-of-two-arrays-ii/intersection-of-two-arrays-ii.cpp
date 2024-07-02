class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        unordered_map<int,int>m1,m2;
        for(int i=0;i<nums1.size();i++){
            m1[nums1[i]]++;
        }
        for(int j=0;j<nums2.size();j++){
            m2[nums2[j]]++;
        }
        vector<int> a;
        for(auto i:m1){
            for(auto j:m2){
                if(i.first==j.first){
                    int x=min(i.second,j.second);
                    while(x--){
                        a.push_back(i.first);
                    }
                }
            }
        }
        return a;
    }
};