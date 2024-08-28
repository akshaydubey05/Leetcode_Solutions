class Solution {

private:
    void dfs(vector<int> adj[],vector<int> ans,int visited[], int node){
        visited[node]=1;
        ans.push_back(node);
        for(auto adj_node: adj[node]){
            if(!visited[adj_node]){
                dfs(adj,ans,visited,adj_node);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int number_of_nodes = isConnected.size();
        vector<int> adj[number_of_nodes];
        for(int i=0;i<number_of_nodes;i++){
            for(int j=0;j<number_of_nodes;j++){
                if(isConnected[i][j] == 1 && i!=j){
                    // NOT a directed graph
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int visited[number_of_nodes];
        for(int i=0;i<number_of_nodes;i++){
            visited[i]=0;
        }
        vector<int> ans;
        int count = 0;
        for(int i=0;i<number_of_nodes;i++){
            if(!visited[i]){
                count++;
                dfs(adj,ans,visited,i);
            }
        }
        for(auto i: ans){
            cout<<i<<" ";
        }
        return count;
    }
};