class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long pairPrice = min<long long>(costBoth, static_cast<long long>(cost1) + cost2);
        long long price1 = min(cost1, costBoth);
        long long price2 = min(cost2, costBoth);
        long long common = min(need1, need2);
        long long extra1 = need1 - common;
        long long extra2 = need2 - common;
        return common * pairPrice + extra1 * price1 + extra2 * price2;
    }
};