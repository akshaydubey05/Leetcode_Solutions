class Solution {
public:
    int lengthOfLastWord(string s) {
        reverse(s.begin(),s.end());
        int k=0;
        for(int i=0;i<s.length();i++){
            if(s[i]==' ' && k==0){
                continue;
            }
            if(s[i]!=' '){
                k++;
            }
            if(s[i]==' ' && k!=0){
                break;
            }

        }
        return k;
    }
};