class Solution {
public:

    bool bfs(int row, int col ,vector<vector<int>>& grid1, vector<vector<int>>& grid2, int rows, int cols, vector<vector<int>>& visited){
        visited[row][col] = 1;
        queue<pair<int,int>> q;
        q.push({row,col});
        
        int row_arr[4] = {0,1,0,-1};
        int col_arr[4] = {1,0,-1,0};
        bool flag = false;
        while(!q.empty()){
            int curr_row = q.front().first;
            int curr_col = q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int new_row = curr_row + row_arr[i];
                int new_col = curr_col + col_arr[i];
                if(new_row>=0&&new_col>=0&&new_row<rows&&new_col<cols&&!visited[new_row][new_col]&&grid2[new_row][new_col]==1){
                    flag=true;
                }
                if(new_row >= 0 && new_col >=0 &&new_row < rows && new_col <cols && !visited[new_row][new_col] && grid2[new_row][new_col]==2){                    
                    visited[new_row][new_col]=1;
                    q.push({new_row,new_col});
                }
            }
        }
        if(flag){
            return 0;
        }
        return 1;
    
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int ans=0;
        int rows = grid1.size();
        int cols = grid1[0].size();
        vector<vector<int>> visited(rows, vector<int> (cols,0));
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid1[i][j]==1 && grid2[i][j]==1){
                    grid2[i][j] = 2;
                }
            }
        }
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(!visited[i][j] && grid2[i][j]==2){
                    if(bfs(i,j,grid1,grid2,rows,cols,visited)){
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};