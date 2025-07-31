class Solution {
public:
    int minDays(vector<int>& b, int m, int k) {
        //long long int x = m*k;
        
        int mini=INT_MAX, maxi=INT_MIN;
        for(int i=0;i<b.size();i++){
            mini=min(mini, b[i]);
            maxi=max(maxi, b[i]);
        }
        int ans=-1;
        while(mini <= maxi){
            int mid = mini + (maxi-mini)/2;
            int cnt=0,book=0;
            for(int j=0;j<b.size();j++){
                if(b[j]<=mid){
                    cnt++;
                }
                else{
                    book+=(cnt/k);
                    cnt=0;
                }
            }
            book+=(cnt/k);
            if(book>=m){
                ans=mid;
                maxi=mid-1;
            }
            else{
                mini=mid+1;
            }
        }
        return ans;
    }
};