class Solution {
public:
    int maxProfit(vector<int>& p) {
        int i=p.size()-1;
        int j=p.size()-2;
        int maxi=0;
        while(j>=0){
            int x = p[i]-p[j];
            if(x<0){
                i=j;
                j--;
            }
            else{
                maxi=max(x,maxi);
                j--;
            }
        }
        return maxi;
    }
};