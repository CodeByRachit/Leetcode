class Solution {
public:
    vector<int> remainingMethods(int n, int k,
                                 vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        for (auto& i : invocations) {
            int u = i[0];
            int v = i[1];
            adj[u].push_back(v);
        }
        queue<int> q;
        vector<bool> vis(n, false);
        q.push(k);
        vis[k] = true;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (auto& j : adj[node]) {
                if (!vis[j]) {
                    vis[j] = true;
                    q.push(j);
                }
            }
        }
       for (int u = 0; u < n; ++u) {
       if (vis[u]) continue;        
       for (int v : adj[u]) {          
        if (vis[v]) {            
            vector<int> ans(n);
            for (int i = 0; i < n; ++i) ans[i] = i;  
            return ans;
        }
    }
}
            vector<int> ans;
            for (int i = 0; i < n; i++) {
                if (!vis[i]) {
                    ans.push_back(i);
                }
            }
            return ans;
        }
    };