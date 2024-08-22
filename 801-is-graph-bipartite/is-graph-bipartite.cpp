class Solution {
public:
    bool dfs(int node, int color, int col[],vector<vector<int>>& graph){
        col[node]=color;
        for(auto i:graph[node]){
            if(col[i]==-1){
                if(dfs(i,!color,col,graph)==false){
                    return false;
                }
            }
            else if(col[i]==color){
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        int col[n];
        for(int i=0;i<n;i++){col[i]=-1;}
        for(int i=0;i<n;i++){
            if(col[i]==-1){
                if(dfs(i,0,col,graph)==false){
                    return false;
                }
            }
        }
        return true;
    }
};