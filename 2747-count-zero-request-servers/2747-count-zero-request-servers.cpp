class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        sort(logs.begin(), logs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        int m = queries.size();
        vector<vector<int>> sortedQueries(m);
        for (int i = 0; i < m; ++i) {
            sortedQueries[i] = {queries[i], i};
        }
        sort(sortedQueries.begin(), sortedQueries.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });
        vector<int> ans(m);
        vector<int> freq(n + 1, 0); 
        int activeServers = 0;
        int l = 0, r = 0;
        int numLogs = logs.size();
        for (int i = 0; i < m; ++i) {
            int qTime = sortedQueries[i][0];
            int origIdx = sortedQueries[i][1];
            int startTime = qTime - x;
            while (r < numLogs && logs[r][1] <= qTime) {
                int serverId = logs[r][0];
                if (freq[serverId] == 0) {
                    activeServers++;
                }
                freq[serverId]++;
                r++;
            }
            while (l < numLogs && logs[l][1] < startTime) {
                int serverId = logs[l][0];
                freq[serverId]--;
                if (freq[serverId] == 0) {
                    activeServers--;
                }
                l++;
            }
            ans[origIdx] = n - activeServers;
        }
        return ans;
    }
};