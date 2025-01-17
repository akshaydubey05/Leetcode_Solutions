class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n = derived.size();
        int ans=0;
        
        // vector<int> og(n,0);
        // og[0] = 1;
        // for(int i=1;i<n;i++){
        //     og[i] = og[i-1] ^ derived[i-1];
        // }
        // if(og[n-1]^og[0]==derived[n-1]){
        //     return true;
        // }
        // og[0] = 0;
        // for(int i=1;i<n;i++){
        //     og[i] = og[i-1] ^ derived[i-1];
        // }
        // if(og[n-1]^og[0]==derived[n-1]){
        //     return true;
        // }
        // return false;

        for(int i=0;i<n;i++){
            ans ^= derived[i];
        }
        return (ans==0);

    }
};