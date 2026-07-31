class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char,int>mp;
        for(auto i:word){
            mp[i]++;
        }
        priority_queue<int>pq;
        for(auto i:mp){
            pq.push(i.second);
        }
        int totalpushes=0;
        int index=0;
        while(!pq.empty()){
            totalpushes+=(1+(index/8))*pq.top();
            pq.pop();
            index++;
        }
        return totalpushes;
    }
};