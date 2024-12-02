class Solution {
public:
    int isPrefixOfWord(string s, string se) {
        int j=0,x=1;
        bool b=false;
        for(int i=0;i<s.length();i++){
            if(s[i] == ' '){
                x++;
                j=0;
                b=false;
            }
            else if((i == 0 || s[i-1] == ' ') && (s[i] == se[j]) ){
                j++;
                b=true;
                if(j==se.length()){
                    return x;
                }
            }
            else if(s[i] == se[j] && b==true){
                j++;
                if(j==se.length()){
                    return x;
                }
            }
            else{
                j=0;
                b=false;
            }
        
        }
        return -1;

    }
};