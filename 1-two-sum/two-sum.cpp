class Solution {
public:
    vector<int> twoSum(vector<int>& n, int t) {
        vector<int> ans;
        for(int i=0;i<n.size();i++){
            for(int j=0;j<n.size();j++){ // N^2
                if(i!=j){
                    int x = n[i]+n[j];
                    if(x==t){
                        ans.push_back(i);
                        ans.push_back(j);
                        return ans;
                    } 
                }   
            }
        }
        return ans;
    }
};