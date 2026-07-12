class Solution {
public:
    struct DSU {
        vector<int> parent;
        vector<int> sz;
        vector<int> edges;
        void init(int n) {
            parent.resize(n); iota(parent.begin(), parent.end(), 0);
            sz.resize(n, 1);
            edges.resize(n);
        }
        int find(int u) {
            if(u != parent[u]) parent[u] = find(parent[u]);
            return parent[u];
        }
        void merge(int u, int v) {
            int pu = find(u), pv = find(v);
            if(sz[pu] < sz[pv]) swap(pu, pv);
            edges[pu]++;
            if(pu != pv) {
                edges[pu] += edges[pv];
                sz[pu] += sz[pv];
                parent[pv] = pu;
            }
        }
    };
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        DSU dsu; dsu.init(n);
        for(auto& edge : edges) {
            int u = edge[0], v = edge[1];
            dsu.merge(u, v);
        }
        int res = 0;
        vector<bool> visited(n);
        for(int i = 0; i < n; i++) {
            int parent = dsu.find(i);
            if(!visited[parent]) {
                visited[parent] = true;
                if(dsu.edges[parent] == (dsu.sz[parent] * (dsu.sz[parent] - 1)) / 2) res++;
            }
        }
        return res;
    }
};