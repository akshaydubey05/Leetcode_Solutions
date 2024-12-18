class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> ans;
        for(int i=0;i<prices.size();i++){
            int j = i+1;
            for(;j<prices.size();j++){
                if(prices[i]<prices[j])
                    continue;
                else{
                    ans.push_back(prices[i]-prices[j]);
                    break;
                }
            }
            if(j==prices.size())
                ans.push_back(prices[i]);
        }
        return ans; 
    }
};