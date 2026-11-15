class Solution {
public:
    int numOfSubarrays(std::vector<int>& arr) {
        long long odd_prefixes = 0;
        int parity = 0;
        for (int x : arr) {
            parity ^= (x & 1);
            odd_prefixes += parity;
        }
        long long even_prefixes = arr.size() + 1 - odd_prefixes;
        return (odd_prefixes * even_prefixes) % 1000000007;
    }
};