class Disjoint{
    public:
    vector<int>parent,rank,size;
    Disjoint(int vertices){
        parent.resize(vertices,0);
        rank.resize(vertices,0);
        size.resize(vertices);
        fill(begin(size),end(size),1);

        for(int i=0;i<vertices;i++){
            parent[i]=i;
        }
    }

    int findPar(int node){
        if(parent[node]==node)
            return node;
        return parent[node]=findPar(parent[node]);          // path-compression in return call statement
    }

// Two ways to implement DSU
    void uninonByRank(int u,int v){
        int ulp_u=findPar(u);
        int ulp_v=findPar(v);
        if(ulp_u==ulp_v)return;         // it means both have same ultimate parent
        if(rank[ulp_u]<rank[ulp_v]){
            parent[ulp_u]=ulp_v;
        }else if(rank[ulp_v]<rank[ulp_u]){
            parent[ulp_v]=ulp_u;
        }else{
            parent[ulp_v]=ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u,int v){
        int ulp_u=findPar(u);
        int ulp_v=findPar(v);
        if(ulp_u==ulp_v)return;         // it means both have same ultimate parent
        if(size[ulp_u]<size[ulp_v]){
            size[ulp_v]+=size[ulp_u];
            parent[ulp_u]=ulp_v;
        }else{
            size[ulp_u]+=size[ulp_v];
            parent[ulp_v]=ulp_u;
        }
    }
};

class Solution {
public:

    bool isValid(int cr,int cc,int size){
        return cr>=0 and cr<size and cc>=0 and cc<size;
    }

    int largestIsland(vector<vector<int>>& grid) {
        int size=grid.size();

        Disjoint ds(size*size);

        vector<pair<int,int>>movements{{-1,0},{1,0},{0,-1},{0,1}};
        int maxIsland=0;

        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++){
                if(grid[i][j]==1){
                    for(auto move:movements){
                        int nr=i+move.first;
                        int nc=j+move.second;
                        if(isValid(nr,nc,size) and grid[nr][nc]==1){
                            // union cell be cell
// Cell will be calculated by : (row*size+col)
                            ds.unionBySize(i*size+j,nr*size+nc);
                        }
                    }   // END OF MOVE
                }   // END OF IF
            }   // END OF SECOND FOR
        }   // END OF FIRST FOR

        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++){
                if(grid[i][j]!=1){
                    set<int>uniq;
// WHY SET? BECAUSE NEIGHBOUR NODE WILL HAVE SAME PARENT AND NO NEED TO CONSIDER SAME PARENT MULTILPLE TIMES
                    for(auto move:movements){
                        int nr=i+move.first;
                        int nc=j+move.second;
                        if(isValid(nr,nc,size) and grid[nr][nc]==1){
                            uniq.insert(ds.findPar(nr*size+nc));
                        }
                    }   // END OF MOVE
                int dummySize=0;
                for(auto in:uniq)dummySize+=ds.size[in];
                maxIsland=max(maxIsland,dummySize+1);
                }   // END OF IF
            }   // END OF SECOND FOR
        }   // END OF FIRST FOR

// TILL NOW WE HAVE NOT HANDLED THAT CASE WHEN ALL CELLS ARE ONE 

    // for(int cell=0;cell<size*size;cell++){
        maxIsland=max(maxIsland,ds.size[ds.findPar(0)]);
    // }

        return maxIsland;
    }
};