class Solution {
public:
    bool ispreandsuf(string a,string b){
        if(a.length()>b.length()){
            return false;
        }
        if (b.substr(0, a.length()) != a){
            return false;
        }
        if (b.substr(b.length() - a.length(), a.length()) != a){
            return false;
        }
        return true;
    }
    int countPrefixSuffixPairs(vector<string>& w) {
        int count=0;
        for(int i=0;i<w.size();i++){
            for(int j=i+1;j<w.size();j++){
                if(ispreandsuf(w[i],w[j])){
                    count++;
                }
            }
        }
        return count;
    }
};