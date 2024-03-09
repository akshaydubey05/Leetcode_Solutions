class Solution {
public:
    int getCommon(vector<int>& n1, vector<int>& n2) {
        int i=0;int j=0;
        int ans=0;
        while(i<n1.size() && j<n2.size()){
            if(n1[i]==n2[j]){
                return n1[i];
            }
            else if(n1[i]<n2[j]){
                i++;
            }
            else{
                j++;
            }
        }
        return -1;
    }
};