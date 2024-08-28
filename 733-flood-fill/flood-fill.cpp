class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int rows = image.size();
        int cols = image[0].size();
        vector<vector<int>> flooded = image;
        queue<pair<int,int>> flood; 
        int prev_color = flooded[sr][sc];
        if(prev_color == color){
            return image;
        }
        flooded[sr][sc] = color;       
        flood.push({sr,sc});
        int row[4] = {0,1,0,-1};
        int col[4] = {1,0,-1,0};
        while(!flood.empty()){
            int current_X = flood.front().first;
            int current_Y = flood.front().second;
            flood.pop();
            for(int i=0;i<4;i++){
                int new_X = current_X + row[i];
                int new_Y = current_Y + col[i];
                if(new_X < 0 || new_Y < 0 || new_X >= rows || new_Y >= cols || flooded[new_X][new_Y] != prev_color){
                    continue;
                }
                flooded[new_X][new_Y] = color;
                flood.push({new_X,new_Y});
            }
        }
        return flooded;
    }
};