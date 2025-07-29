class Solution {
public:
    int minEatingSpeed(vector<int>& p, int h) {
        int n = p.size();
        int maxi = INT_MIN;
        for(int i=0;i<p.size();i++){
            maxi=max(maxi,p[i]);
        }
        int l=1,hi=maxi-1;
        while(l<=hi){
            int mid =(l+hi)/2;
            long long int x=0;
            for(int j=0;j<n;j++){
                x += ceil((double)p[j]/(double)(mid));
            }
            if(x<=h){
                hi=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return l;
        return 0;
    }
};