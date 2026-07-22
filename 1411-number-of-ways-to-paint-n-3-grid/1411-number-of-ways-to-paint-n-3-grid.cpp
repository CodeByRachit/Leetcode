class Solution {
public:
    int numOfWays(int n) {
        const long long MOD = 1000000007;
        long long twoColor = 6;
        long long threeColor = 6;
        for (int row = 2; row <= n; ++row){
            long long nextTwoColor = ( 3 * twoColor + 2 * threeColor) % MOD;
            long long nextThreeColor = ( 2 * twoColor + 2 * threeColor) % MOD;
            twoColor = nextTwoColor;
            threeColor = nextThreeColor;
        }
        return static_cast<int>((twoColor + threeColor) % MOD);
    }
};