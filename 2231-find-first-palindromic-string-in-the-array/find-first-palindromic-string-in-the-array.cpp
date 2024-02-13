class Solution {
public:
    bool is_palindrome(string s){
        string p=s;
        reverse(p.begin(),p.end());
        if(p==s){
            cout<<"a";
            return true;
        }
        else{
            return false;
        }
    }
    string firstPalindrome(vector<string>& w) {
        string s="";
        for(int i=0;i<w.size();i++){
            if(is_palindrome(w[i])==true){
                cout<<"b";
                s=w[i];
                break;
            }
        }
        return s;
    }
};