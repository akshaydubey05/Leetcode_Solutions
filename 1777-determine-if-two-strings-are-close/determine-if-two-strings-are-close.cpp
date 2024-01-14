class Solution {
public:
    bool closeStrings(string w1, string w2) {
        if(w1.length()!=w2.length()){
            return false;
        }
        vector<int> a(26,0);
        vector<int> b(26,0);
        for(auto i:w1){
            a[i-'a']++;
        }
        for(auto i:w2){
            b[i-'a']++;
        }
        for(int i=0;i<26;i++){
            if((a[i]==0 && b[i]!=0) || (a[i]!=0 && b[i]==0)){
                return false;
            }
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        for(int i=0;i<a.size();i++){
            if(a[i]!=b[i]){
                return false;
            }
        }
        return true;

    }
};