class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();
        const long long INF = 1e18;
        multiset<int> low, high;
        long long sumLow = 0, sumHigh = 0;
        auto add = [&](int v) {
            if (low.empty() || v <= *low.rbegin()) {
                low.insert(v);
                sumLow += v;
            } else {
                high.insert(v);
                sumHigh += v;
            }
            if (low.size() > high.size() + 1) {
                int t = *low.rbegin();
                low.erase(prev(low.end()));
                sumLow -= t;
                high.insert(t);
                sumHigh += t;
            }
            if (low.size() < high.size()) {
                int t = *high.begin();
                high.erase(high.begin());
                sumHigh -= t;
                low.insert(t);
                sumLow += t;
            }
        };
        auto remove = [&](int v) {
            if (low.find(v) != low.end()) {
                low.erase(low.find(v));
                sumLow -= v;
            } else {
                high.erase(high.find(v));
                sumHigh -= v;
            }
            if (low.size() > high.size() + 1) {
                int t = *low.rbegin();
                low.erase(prev(low.end()));
                sumLow -= t;
                high.insert(t);
                sumHigh += t;
            }
            if (low.size() < high.size()) {
                int t = *high.begin();
                high.erase(high.begin());
                sumHigh -= t;
                low.insert(t);
                sumLow += t;
            }
        };
        vector<long long> cost(n - x + 1);
        for (int i = 0; i < n; i++) {
            add(nums[i]);
            if (i >= x) remove(nums[i - x]);
            if (i >= x - 1) {
                long long median = *low.rbegin();
                cost[i - x + 1] =
                    median * low.size() - sumLow +
                    sumHigh - median * high.size();
            }
        }
        vector<vector<long long>> dp(
            k + 1, vector<long long>(n + 1, INF)
        );
        for (int i = 0; i <= n; i++)
            dp[0][i] = 0;
        for (int j = 1; j <= k; j++) {
            for (int i = 1; i <= n; i++) {
                dp[j][i] = dp[j][i - 1];
                if (i >= x && dp[j - 1][i - x] != INF) {
                    dp[j][i] = min(
                        dp[j][i],
                        dp[j - 1][i - x] + cost[i - x]
                    );
                }
            }
        }
        return dp[k][n];
    }
};