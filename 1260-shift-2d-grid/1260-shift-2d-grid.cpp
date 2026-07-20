class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int mn = m * n;
        k %= mn;
        if (!k) return grid;
        int cycles = gcd(k, mn);
        int cycle_len = mn / cycles;
        for (int s = 0; s < cycles; ++s) {
            int held = grid[s / n][s % n];
            int i = s + k;
            for (int j = 0; j < cycle_len; ++j) {
                swap(held, grid[i / n][i % n]);
                i = (i + k) % mn;
            }
        }
        return grid;
    }
};