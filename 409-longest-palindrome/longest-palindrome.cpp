class Solution {
public:
    int longestPalindrome(string s) {
        sort(s.begin(),s.end());
        if(s.length()==1){
            return 1;
        }
        unordered_map<char,int> m;
        for(auto i:s){
            m[i]++;
        }
        int ans=0;
        bool b=false;
        for(auto i:m){
            if(i.second%2==0){
                ans+=i.second;
            }
            else{
                ans+=i.second-1;
                b=true;
            }
        }
        if(b){
            ans++;
        }
        return ans;
    }
};