class Solution {
public:
    int daisy(int mid, vector<int>&w){
        int days=1,load=0;
        for(int i=0;i<w.size();i++){
            if(load+w[i]>mid){
                days++;
                load=w[i];
            }
            else{
                load+=w[i];
            }
        }
        return days;
    }
    int shipWithinDays(vector<int>& w, int d) {
        int low = *max_element(w.begin(), w.end());
        int high = accumulate(w.begin(), w.end(), 0);
        while(low <=high){
            int mid = low+(high-low)/2;
            int x = daisy(mid,w);
            if(x<=d){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};