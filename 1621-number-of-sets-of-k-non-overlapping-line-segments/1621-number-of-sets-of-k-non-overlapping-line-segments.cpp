static constexpr int MOD = 1e9 + 7, MAX = 2000;
static constexpr long long modPow(long long b, int exp) {
    long long res = 1;
    while(exp){
        if(exp & 1) res = (res * b) % MOD;
        b = (b * b) % MOD;
        exp >>= 1;
    }
    return res;
}
static constexpr auto inv = []() {
    array<int, MAX> inv_f{};
    long long f = 1;
    for(int i = 1; i < MAX; ++i) f = (f * i) % MOD;
    inv_f[MAX - 1] = modPow(f, MOD - 2);
    inv_f[0] = 1;
    for(int i = MAX - 2; i >= 1; --i) inv_f[i] = (1LL * inv_f[i + 1] * (i + 1)) % MOD;
    return inv_f;
}();
class Solution {
public:
    int numberOfSets(int n, int k) {
        const int N = n + k - 1, R = k << 1;
        long long factN = modPow(inv[N] , MOD - 2);
        return (((factN * inv[R]) % MOD) * inv[N - R]) % MOD;
    }
};