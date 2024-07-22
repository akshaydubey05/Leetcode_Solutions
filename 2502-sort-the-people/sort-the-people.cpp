class Solution {
public:
    vector<string> sortPeople(vector<string>& n, vector<int>& h) {
        ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
        vector<pair<int,string>> p;
        for(int i=0;i<n.size();i++){
            p.push_back(make_pair(h[i],n[i]));
        }
        sort(p.begin(),p.end());
        reverse(p.begin(),p.end());
        vector<string>s;
        for(int i=0;i<p.size();i++){
            s.push_back(p[i].second);
        }
        for(auto i: p){
            cout<<i.first<<" "<<i.second;
        }
        return s;
    }
};