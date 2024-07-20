class Solution {
public:
    void setZeroes(vector<vector<int>>& m) {
       int r=m.size();
       int c=m[0].size();
       vector<int> row(r,0);
       vector<int> col(c,0);
       for(int i=0;i<m.size();i++){
        for(int j=0;j<m[0].size();j++){
            if(m[i][j]==0){
                row[i]=1;
                col[j]=1;
            }
        }
       }
       for(int i=0;i<m.size();i++){
        for(int j=0;j<m[0].size();j++){
            if(row[i] || col[j]){
                m[i][j]=0;
            }
        }
       }
    }
};