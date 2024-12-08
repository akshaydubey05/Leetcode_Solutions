class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        vector<vector<int>> lineSweep;
        for(auto& event: events){
            int start=event[0];
            int end=event[1];
            int value=event[2];
            lineSweep.push_back({start,1,value});
            lineSweep.push_back({end+1,-1,value});
        }
        sort(lineSweep.begin(),lineSweep.end());

        int maxValue=0;
        int maxSeen=0;
        for(auto& lsw:lineSweep){
            int point=lsw[0];
            int status=lsw[1];
            int val=lsw[2];

            if(status==1){
                maxValue=max(maxValue,maxSeen+val);
            }
            if(status==-1){
                maxSeen=max(maxSeen,val);
            }
        }

        return maxValue;
        
    }
};