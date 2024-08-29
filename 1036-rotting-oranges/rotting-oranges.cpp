class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if(grid.size() == 0){
            return 0;
        }
        int rows = grid.size();
        int cols = grid[0].size();
        int time=0, total=0, count = 0;
        queue<pair<int,int>> rotten_idx;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j] != 0){
                    total++;
                }
                if(grid[i][j] == 2){
                    rotten_idx.push({i,j});
                }
            }
        }
        int row[4] = {0,1,0,-1};
        int col[4] = {1,0,-1,0};
        while(!rotten_idx.empty()){
            int k=rotten_idx.size();
            count+=k;
            while(k--){
                int current_X = rotten_idx.front().first;
                int current_Y = rotten_idx.front().second;
                rotten_idx.pop();
                for(int i=0;i<4;i++){
                    int new_X = current_X + row[i];
                    int new_Y = current_Y + col[i];
                    if(new_X<0 || new_Y<0 || new_X>=rows || new_Y>=cols || grid[new_X][new_Y]!=1){
                        continue;
                    }
                    grid[new_X][new_Y]=2;
                    rotten_idx.push({new_X,new_Y});
                }
                
            }
            if(!rotten_idx.empty()){
                time++;
            }
        }
        if(count==total){
            return time;
        }
        return -1;
    }
};