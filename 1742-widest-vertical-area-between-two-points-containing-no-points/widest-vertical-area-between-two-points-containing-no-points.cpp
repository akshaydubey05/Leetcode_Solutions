class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& p) {
        vector<int> a;
        for(int i=0;i<p.size();i++){
            a.push_back(p[i][0]);
        }
        sort(a.begin(),a.end());
        int max_area=0;
        for(int i=0;i<a.size()-1;i++){
            if(max_area<(a[i+1]-a[i])){
                max_area=(a[i+1]-a[i]);
            }
        }
        //cout<<max_area<<" ";
        return max_area;
    }
};