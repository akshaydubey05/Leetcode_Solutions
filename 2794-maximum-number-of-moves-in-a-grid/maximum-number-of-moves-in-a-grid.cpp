class Solution {
public:
    int dfs(vector<vector<int>>& grid, int& m, int& n, int i, int j)
    {
        if(grid[i][j] == 0) return 0;

        int k=grid[i][j];
        grid[i][j]=0;//prevent meeting the same cell
        int right=0;
        int tright=0;
        int bright=0;
        if(j < n-1) //can move right
        {
            if(k < grid[i][j+1]) //right
            {
                right= 1+dfs(grid, m, n, i, j+1);
            }

            if(i>0 && k<grid[i-1][j+1]) //can move right_up
            {
                tright= 1+dfs(grid, m, n, i-1, j+1);
            }
            if(i<m-1 && k<grid[i+1][j+1]) //can move right_down
            {
                bright= 1+dfs(grid, m, n, i+1, j+1);
            }
        }

        //return maxstep
        return max(right, max(tright, bright));
    }

    int maxMoves(vector<vector<int>>& grid) 
    {
        //Can only move right right_up right_down
        int m=grid.size();
        int n=grid[0].size();
        int maxstep=0;
        for(int i=0; i<m; ++i) //see through first col
        {
            int t=dfs(grid, m, n, i, 0);
            maxstep=max(maxstep, t);
            //the max move can be is (length of col)-1
            if(maxstep == n-1) return maxstep;
        }
        
        return maxstep;
    }
};