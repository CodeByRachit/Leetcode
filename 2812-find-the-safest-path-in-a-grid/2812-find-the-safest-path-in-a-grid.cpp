class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<vector<int>> que;
        if (grid[0][0] == 1 || grid[m - 1][n - 1] == 1)
            return 0;
        vector<vector<int>> manhattan(m, vector<int>(n, -1));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    que.push({i, j});
                    manhattan[i][j] = 0;
                }
            }
        }
        vector<vector<int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
        while (!que.empty()) {
            auto x = que.front();
            que.pop();
            int i = x[0];
            int j = x[1];
            for (auto d : dir) {
                int newi = i + d[0];
                int newj = j + d[1];
                if (newi < 0 || newj < 0 || newi >= m || newj >= n ||
                    manhattan[newi][newj] != -1)
                    continue;
                manhattan[newi][newj] = manhattan[i][j] + 1;
                que.push({newi, newj});
            }
        }
        vector<vector<int>> distance(m, vector<int>(n, INT_MIN));
        distance[0][0] = manhattan[0][0];
        priority_queue<vector<int>> pq;
        pq.push({manhattan[0][0], 0, 0});
        while (!pq.empty()) {
            auto x = pq.top();
            pq.pop();
            int safe = x[0];
            int i = x[1];
            int j = x[2];
            if (safe < distance[i][j])
                continue;
            if (i == m - 1 && j == n - 1)
                return safe;
            for (auto d : dir) {
                int newi = i + d[0];
                int newj = j + d[1];
                if (newi < 0 || newj < 0 || newi >= m || newj >= n)
                    continue;
                int newSafe = min(safe, manhattan[newi][newj]);
                if (newSafe > distance[newi][newj]) {
                    distance[newi][newj] = newSafe;
                    pq.push({newSafe, newi, newj});
                }
            }
        }
        return -1;
    }
};