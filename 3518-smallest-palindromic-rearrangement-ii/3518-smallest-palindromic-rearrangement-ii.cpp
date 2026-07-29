class Solution {
public:
    const long long LIM = 1e6 + 1;
    long long f(vector<int>& c) {
        int n = accumulate(c.begin(), c.end(), 0);
        long long ans = 1;
        for (int x : c) {
            for (int i = 1; i <= x; i++)
                ans = min(LIM, ans * (n - x + i) / i);
            n -= x;
        }
        return ans;
    }
    string smallestPalindrome(string s, int k) {
        vector<int> c(26);
        for (char x : s) c[x - 'a']++;
        string mid, L;
        for (int i = 0; i < 26; i++) {
            if (c[i] & 1) mid += char('a' + i);
            c[i] /= 2;
        }
        if (f(c) < k) return "";
        for (int i = 0; i < s.size() / 2; i++) {
            for (int j = 0; j < 26; j++) {
                if (!c[j]) continue;
                c[j]--;
                long long t = f(c);
                if (t >= k) {
                    L += char('a' + j);
                    break;
                }
                k -= t;
                c[j]++;
            }
        }
        string R = L;
        reverse(R.begin(), R.end());
        return L + mid + R;
    }
};