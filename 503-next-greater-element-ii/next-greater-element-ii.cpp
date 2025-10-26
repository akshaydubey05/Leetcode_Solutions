class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        int n=nums.size();
        nums.insert(nums.end(),nums.begin(),nums.end());
        for(auto i:nums){
            cout<<i<<" ";
        }
        vector<int> ans(2*n,-1);
        for(int i=2*n-1;i>=0;i--){
            while(!st.empty() && st.top()<=nums[i]){
                st.pop();
            }
            if(st.empty()){
                ans[i] = -1;
            }
            else{
                ans[i] = st.top();
            }
            st.push(nums[i]);
        }
        ans.resize(n);
        return ans;
    }

};