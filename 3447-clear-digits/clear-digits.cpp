class Solution {
public:
    string clearDigits(string s) {
        string x;
        for(int i=0;i<s.length();i++){
            if(isdigit(s[i]) && !x.empty()){
                x.pop_back();
            }
            else{
                x+=s[i];
            }
        }
        return x;
        
    }
};