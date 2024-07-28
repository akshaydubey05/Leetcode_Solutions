class Solution {
private:
    void dfs(int row,int col,vector<vector<int>> &vis,vector<vector<int>> &b,int roww[],int coll[]){
        vis[row][col]=1;
        int n=b.size(),m=b[0].size();
        for(int i=0;i<4;i++){
            int newrow = row + roww[i];
            int newcol = col + coll[i];
            if(newrow>=0 && newrow<n && newcol>=0 && newcol<m && !vis[newrow][newcol] && b[newrow][newcol]==1){
                dfs(newrow,newcol,vis,b,roww,coll);
            }
        }
    }
public:
    int numEnclaves(vector<vector<int>>& b) {
        int n=b.size(),m=b[0].size();
        int row[]={0,0,1,-1};
        int col[]={1,-1,0,0};
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int j=0;j<m;j++){
            if(!vis[0][j] && b[0][j]==1){
                dfs(0,j,vis,b,row,col);
            }
            if(!vis[n-1][j] && b[n-1][j]==1){
                dfs(n-1,j,vis,b,row,col);
            }
        }
        for(int i=0;i<n;i++){
            if(!vis[i][0] && b[i][0]==1){
                dfs(i,0,vis,b,row,col);
            }
            if(!vis[i][m-1] && b[i][m-1]==1){
                dfs(i,m-1,vis,b,row,col);
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && b[i][j]==1){
                    ans++;
                }
            }
        }
        return ans;
    }
};