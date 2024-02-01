class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& n, int k) {
        if(n.size()%3!=0){
            return vector<vector<int>>();
        }
        sort(n.begin(),n.end());
        vector<vector<int>> a(n.size()/3,vector<int>(3));
        int groupindex=0;
        for(int i=0;i<n.size();i+=3){
            if(i+2<n.size() && n[i+2]-n[i]<=k){
                a[groupindex]={n[i],n[i+1],n[i+2]};
                groupindex++;
            }
            else{
                return vector<vector<int>>();
            }
        }
        return a;
    }
};