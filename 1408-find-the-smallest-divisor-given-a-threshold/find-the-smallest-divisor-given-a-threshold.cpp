class Solution {
public:
    int smallestDivisor(vector<int>& n, int t) {
        int maxi=INT_MIN;
        for(int i=0;i<n.size();i++){
            maxi=max(maxi,n[i]);
        }
        int low =1;
        int high = maxi;
        while(low <= high){
            int mid = low+(high-low)/2;
            int sum=0;
            for(int i=0;i<n.size();i++){
                sum+=ceil((double)(n[i])/(double)(mid));
            }
            if(sum<=t){
                high=mid-1;
            }
            else {
                low=mid+1;
            }
        }
        return low;
    }
};