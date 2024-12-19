class Solution {
public:
    int mini = 1;
    void f(vector<int> &a, int index, set<int> st, vector<set<int>> v){
        if(index >= a.size()){
            if(st.size()) v.push_back(st);
            vector<int> b;
            for(auto e:v){
                for(auto j:e){
                    b.push_back(j);
                }
            }
            if(is_sorted(b.begin(), b.end())){
                mini = max(mini, (int)v.size());
            }
            return ;
        }

        //do not split
        st.insert(a[index]);
        f(a, index+1, st, v);

        //do split
        v.push_back(st);
        st.clear();
        f(a, index+1, st, v);
        v.pop_back();
    }
    int maxChunksToSorted(vector<int>& a) {
        set<int> st;
        vector<set<int>> v;
        f(a, 0, st, v);
        return mini;
    }
};