class Solution {
private:
    bool isvalid(int x, int y, int n, int m){
        return x>=0 && y>=0 && x<n && y<m;
    }
public:
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<pair<int,int>> move = {{0,1},{0,-1},{1,0},{-1,0}};
        vector<vector<int>> dist(n, vector<int>(m,INT_MAX));
        vector<vector<bool>> vis(n, vector<bool>(m,false));
        dist[0][0] = 0;
        deque<pair<int, int>> dq;
        dq.push_back({0,0});
        while(!dq.empty()){
            auto cur = dq.front();
            int x = cur.first;
            int y = cur.second;
            dq.pop_front();
            vis[x][y] = true;
            if(x == n-1 && y == m-1){
                return dist[x][y];
            }
            for(int i=0;i<4;i++){
                int dx = x + move[i].first;
                int dy = y + move[i].second;
                if(!isvalid(dx, dy, n, m)){
                    continue;
                }
                if(vis[dx][dy]){
                    continue;
                }
                int wt;
                if(i+1 == grid[x][y]){
                     wt = 0;
                }
                else{
                     wt = 1;
                }
                if(dist[dx][dy] > dist[x][y] + wt){
                    dist[dx][dy] = dist[x][y] + wt;
                    if(wt == 0){
                        dq.push_front({dx,dy});
                    }
                    else{
                        dq.push_back({dx,dy});
                    }
                }
            }
        }
        return dist[n-1][m-1];

    }
};