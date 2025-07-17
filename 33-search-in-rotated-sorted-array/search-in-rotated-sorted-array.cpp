class Solution {
public:
    int search(vector<int>& a, int t) {
        for(int i=0;i<a.size();i++){
            if(a[i]==t){
                return i;
            }
        }
        return -1;
    }
};