class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1 || numRows>=s.length()){
            return s;
        }
        string ans="";
        int i=0, ss=1;
        vector<vector<char>> vs(numRows);
        for(auto o:s){
            vs[i].push_back(o);
            if(i==0){
                ss=1;
            }
            else if(i==numRows-1){
                ss=-1;
            }
            i+=ss;
        }
        for(int i=0;i<vs.size();i++){
            for(int j=0;j<vs[i].size();j++){
                ans+=vs[i][j];
            }
        }
        return ans;
    }
};