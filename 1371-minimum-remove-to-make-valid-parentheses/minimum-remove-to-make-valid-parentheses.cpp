class Solution {
public:
    string minRemoveToMakeValid(string st) {
        // return s;
        int open=0;
        vector<char> s(st.begin(),st.end());
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                open++;
            }
            else if(s[i]==')'){
                if(open==0){
                    s[i]='*';
                }
                else{
                    open--;
                }
            }
        }
        for(int i=s.size()-1;i>=0;i--){
                if(open>0 && s[i]=='('){
                    s[i]='*';
                    open--;
                }
            }
            string res="";
            for(char i:s){
                if(i!='*'){
                    res+=i;
                }
            }
            return res;
    }
};