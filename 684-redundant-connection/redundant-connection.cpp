struct ds_node {
    ds_node *parent = nullptr;
    uint64_t rank = 0;
};

void ds_union(ds_node *s1, ds_node *s2) {
    if(s1->rank > s2->rank)
        s2->parent = s1;
    else if(s2->rank > s1->rank)
        s1->parent = s2;
    else {
        s2->parent = s1;
        s1->rank++;
    }
}

ds_node* ds_find(ds_node *s) {
    if(s->parent) {
        s->parent = ds_find(s->parent);
        return s->parent;
    }
    return s;
}

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& __restrict__ edges) {
        size_t n = edges.size();
        vector<ds_node> v(n);
        ds_node *z1, *z2;
        for(const vector<int> &e : edges) {
            z1 = ds_find(&v[e[0]-1]);
            z2 = ds_find(&v[e[1]-1]);
            if(z1 == z2)
                return e;
            ds_union(z1,z2);
        }
        abort();
    }
};