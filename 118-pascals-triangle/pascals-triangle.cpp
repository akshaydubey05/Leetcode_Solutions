class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> ans{{1}};
        if(n==1){
            return ans;
        }
        for(int i=1;i<n;i++){
            vector<int> s;
            for(int j=0;j<=i;j++){
                if(j == 0 || j == i){
                    s.push_back(1);
                }
                else{
                    s.push_back(ans[i-1][j-1] + ans[i-1][j]);
                }
                
            }
            ans.push_back(s);
        }
        return ans;
    }
};