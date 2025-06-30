class Solution {
public:
    int maxProfit(vector<int>& p) {
        int mini = p[0];
        int maxi = 0;
        for(int i=0;i<p.size();i++){
            if(p[i]<mini){
                mini=p[i];
            }
            maxi=max(maxi,p[i]-mini);
        }
        return maxi;
    }
};