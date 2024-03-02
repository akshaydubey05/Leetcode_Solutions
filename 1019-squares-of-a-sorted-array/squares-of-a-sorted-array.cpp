class Solution {
public:
    vector<int> sortedSquares(vector<int>& n) {
        for(int i=0;i<n.size();i++){
            if(n[i]<0){
                n[i]=abs(n[i]);
            }
        }
        sort(n.begin(),n.end());
        for(int i=0;i<n.size();i++){
            n[i]=pow(n[i],2);
        }
        return n;
    }
};