class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& m) {
        vector<int>ans;
        int left=0,top=0,bottom=m.size()-1,right=m[0].size()-1;
        while(top<=bottom && left<=right ){
            for(int i=left;i<=right;i++){
            ans.push_back(m[top][i]);
        }
        top++;
        for(int i=top;i<=bottom;i++){
            ans.push_back(m[i][right]);
        }
        right--;
        if(top<=bottom){
            for(int i=right;i>=left;i--){
            ans.push_back(m[bottom][i]);
        }
        bottom--;
        }
        if(left<=right){
            for(int i=bottom;i>=top;i--){
            ans.push_back(m[i][left]);
        }
        left++;
        }
        }
        return ans;
    }


};