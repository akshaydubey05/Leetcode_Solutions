class Solution {
public:
    int missingNumber(vector<int>& n) {
        int sum=0;
        for(int i=0;i<n.size();i++){
            sum+=n[i];
        }
        int tsum=n.size()*(n.size()+1)/2;
        //cout<<tsum-sum<<endl;
        return tsum-sum;
    }
};