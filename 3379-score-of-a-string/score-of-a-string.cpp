class Solution {
public:
    int scoreOfString(string s) {
        int ans=0;
        for(int i=0;i<s.length()-1;i++){
            int x=abs(s[i]-s[i+1]);
            ans+=x;
        }
        //ans+=abs(s[0]-s[s.length()-1]);
        return ans;
    }
};