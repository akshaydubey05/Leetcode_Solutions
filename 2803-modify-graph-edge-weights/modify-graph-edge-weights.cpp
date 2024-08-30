class Solution {
public:
    const int INF = 2e9;
    int dijkstra(int n, int src, int dest, vector<pair<int,int>> adj[]){
        vector<int> dist(n,1e9);
        dist[src] = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,src});
        while(!pq.empty()){
            int node_dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if(node == dest){
                break;
            }
            for(auto adj_node : adj[node]){
                int neighbour = adj_node.first;
                int neigh_dist = adj_node.second;
                if(node_dist + neigh_dist < dist[neighbour]){
                    dist[neighbour] = node_dist + neigh_dist;
                    pq.push({dist[neighbour],neighbour});
                }
            }
        } 
        return dist[dest];
    }

    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int src, int dest, int target) {
        vector<pair<int,int>> adj[n];
        for(auto it : edges){
            int vtx1 = it[0];
            int vtx2 = it[1];
            int weight = it[2];
            if(weight == -1){
                continue;
            }
            adj[vtx1].push_back({vtx2,weight});
            adj[vtx2].push_back({vtx1,weight});
        }
        int length_of_shortest_path = dijkstra(n, src, dest, adj);
        if(length_of_shortest_path < target){
            return {};
        }
        bool same = (length_of_shortest_path == target);
        
        for(auto &edge : edges){
            if(edge[2] != -1){
                continue;
            }
            edge[2] = same ? INF : 1;
            adj[edge[0]].push_back({edge[1],edge[2]});
            adj[edge[1]].push_back({edge[0],edge[2]});
            if(!same){
                int newshortestpath =  dijkstra(n,src,dest,adj);
                if(newshortestpath <= target){
                    same = true;
                    edge[2] += target-newshortestpath;
                }
            }
        }if(same){
            return edges;
        }
        return {};
    }
};