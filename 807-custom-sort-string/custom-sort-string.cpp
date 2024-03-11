class Solution {
public:
    string customSortString(string order, string s) {
        string same="";
        for(int i=0;i<order.length();i++){
            for(int j=0;j<s.length();j++){
                if(order[i]==s[j]){
                    same+=order[i];
                }
            }
        }
        string left="";
        bool b=true;
        for(int i=0;i<s.length();i++){
            for(int j=0;j<order.length();j++){
                if(s[i]==order[j]){
                    b=false;
                }
            }
            if(b){
                left+=s[i];
            }
            b=true;
        }
        string ans=same+left;
        cout<<same<<" "<<left;
        return ans;
    }
};