class Solution {
public:
    bool isSubsequence(string s, string t) {
        bool b=false;
        int j=0;
        int i=0;
        while(i<t.length()){
            if(t[i]==s[j]){
                i++;
                j++;
            }
            else{
                i++;
            }
        }
        if(j<s.length()){
            return false;
        }
        return true;
    }
};