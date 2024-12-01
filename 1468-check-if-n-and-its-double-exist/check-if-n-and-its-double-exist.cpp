class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        int ans = 0;
        int n = arr.size();
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                if(i!=j){
                    if(arr[i] == 2*arr[j]){
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};