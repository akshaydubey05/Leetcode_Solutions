class Solution {
public:
    int minDays(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        auto countisland = [&](){
            vector<vector<bool>>visited(m , vector<bool>(n , false));
            int islands =0 ;
            function <void(int , int)>dfs = [&](int x , int y){
                if(x < 0 || x >= m || y < 0 || y >= n || grid[x][y] ==0 || visited[x][y])return ;
                visited[x][y]= true;
                dfs(x+1 , y);
                dfs(x-1, y);
                dfs(x , y+1);
                dfs(x , y-1);

            };
            for(int i = 0 ; i < m ; i++){
                for(int j = 0 ; j < n ; j++){
                    if(grid[i][j] ==1 && !visited[i][j]){
                        islands++;
                        dfs(i , j);
                    }
                }
            }
            return islands;
        };
        if(countisland() != 1)return 0;

        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j] ==1){
                    grid[i][j] = 0;
                    if(countisland() != 1){
                        return 1;
                    }
                    grid[i][j] =1;
                }
            }
        }
        return 2;
    }
};