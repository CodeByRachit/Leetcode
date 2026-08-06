class Solution {
public:
    int f(int x) {
        int acc = 1;
        while (x) {
            acc *= x % 10;
            x /= 10;
        }
        return acc;
    }
    int smallestNumber(int n, int t) {
        for (int i = n; i <= 100; ++i) {
            if (f(i) % t == 0) return i;
        }
        return -1;
    }
};