class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int c1 = 0, n = s.size() + 2, i = 0;
        while (i < n - 2) {
            if (s[i] == '1') c1++;
            i++;
        }
        s = "1" + s + "1";
        int j = 0, ans = c1, cl0 = 0;
        while (j < n && s[j] == '1') j++;
        while (j < n && s[j] == '0') cl0++, j++;
        while (j < n) {
            int cm1 = 0, cr0 = 0;
            while (j < n && s[j] == '1') cm1++, j++;
            if (cm1 == 0) break;
            while (j < n && s[j] == '0') cr0++, j++;
            if (cr0 == 0) break;
            ans = max(ans, c1 + cl0 + cr0);
            cl0 = cr0;
        }
        return ans;
    }
};