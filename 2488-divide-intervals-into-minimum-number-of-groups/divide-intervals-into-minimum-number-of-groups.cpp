class Solution {
public:
    int minGroups(vector<vector<int>>& interval) {
        sort(interval.begin(), interval.end());
        for(auto i = 0; i < interval.size();i++){
            cout << interval[i][0] << " " << interval[i][1] << endl;
        }
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto it : interval){
            int s = it[0];
            int e = it[1];
            if(!pq.empty() && pq.top() < s){
                pq.pop();
            }
            pq.push(e);
        }
        return pq.size();
    }
};