class Solution {
public:
    string getHappyString(int n, int k) {
        string curr  ="";
        vector<string> all;
        adding(n ,curr, all);
        if(k>all.size()){
            return "";
        }
        sort(all.begin(),all.end());
        return all[k-1];
    }
    void adding(int n, string curr ,vector<string>& all){
        if(curr.size()==n){
            all.push_back(curr);
            return ;
        }
        for(auto i='a';i<='c';i++){
            if(curr.size()>0 && curr.back()==i){
                continue;
            }
            adding(n, curr+i, all);
        }
    }
};