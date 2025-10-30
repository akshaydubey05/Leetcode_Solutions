class Solution {
public:
    vector<int> asteroidCollision(vector<int>& as) {
        stack<int> st;
        for(int i=0;i<as.size();i++){
            if(as[i]>0){
                st.push(as[i]);
            }
            else{
                while(!st.empty() && st.top()>0 && st.top()<abs(as[i])){
                    st.pop();
                }
                if(!st.empty() && st.top() == abs(as[i])){
                    st.pop();
                }
                else if(st.empty() || st.top()<0){
                    st.push(as[i]);
                }
            }
        }
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        for(auto i:ans){
            cout<<i<<" ";
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};