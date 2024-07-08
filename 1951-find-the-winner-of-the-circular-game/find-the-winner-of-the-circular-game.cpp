class Solution {
public:
    int findTheWinner(int n, int k) {
        /* vector<int> a;
        for(int i=0;i<n;i++){
            a.push_back(i+1);
        } */
        int ans=0;
        for(int i=1;i<=n;i++){
            ans=(ans+k)%i;
        }
        return ans+1;
    }
};