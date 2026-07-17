class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int m = *max_element(nums.begin(), nums.end());
        vector<int> freq(m + 1, 0);
        vector<long long> pairs(m + 1, 0);
        for (int x : nums) freq[x]++;
        for (int i = m; i >= 1; --i) {
            long long c = 0;
            for (int j = i; j <= m; j += i) c += freq[j];
            pairs[i] = c * (c - 1) / 2;
            for (int j = 2 * i; j <= m; j += i) pairs[i] -= pairs[j];
        }
        for (int i = 1; i <= m; ++i) pairs[i] += pairs[i - 1];
        vector<int> ans;
        ans.reserve(queries.size());
        for (long long q : queries) {
            ans.push_back(upper_bound(pairs.begin(), pairs.end(), q) - pairs.begin());
        }
        return ans;
    }
};