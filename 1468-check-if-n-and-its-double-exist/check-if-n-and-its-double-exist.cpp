class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        int ans = 0;
        for(int i = 0;i < arr.size();i++){
            for(int j = 0;j < arr.size();j++){
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