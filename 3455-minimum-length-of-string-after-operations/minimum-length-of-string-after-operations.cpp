class Solution {
public:
    int minimumLength(string s) {
        map<char,int> m;
        for(auto i:s){
            m[i]++;
        }
        int ans=s.length();
        for(auto i:m){
            if(i.second%2!=0 && i.second>1){
                ans-=(i.second-1);
            }
            else{
                if(i.second>2){
                    ans-=(i.second-2);
                }
            }
        }
        return ans;
    }
};