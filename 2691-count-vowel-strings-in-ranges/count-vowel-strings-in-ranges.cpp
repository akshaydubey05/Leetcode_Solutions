class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> b;
        set<char> s;
        s.insert('a');s.insert('e');s.insert('i');s.insert('o');s.insert('u');
        int n = words.size();
        for(int i=0;i<n;i++){
            string st = words[i];
            if(s.find(st[0])!=s.end() && s.find(st[st.length()-1]) != s.end()){
                b.push_back(1);
            }
            else{
                b.push_back(0);
            }
        }
        vector<int> prefix(n);
        prefix[0] = b[0];
        for(int i=1;i<n;i++){
            prefix[i] = prefix[i-1] + b[i];
        }
        vector<int> ans(queries.size());
        for(int i=0;i<queries.size();i++){
            int x = queries[i][0];
            if(x>0){
                x=prefix[queries[i][0]-1];
            }
            else{
                x=0;
            }
            ans[i] = prefix[queries[i][1]]-x;
        }
        return ans;
    }
};