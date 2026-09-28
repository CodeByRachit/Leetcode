class Solution {
public:
    int maxDepth(string s) {
        int left = 0;
        int right = 0;
        int max1 = 0;
        for (char i : s) {
            if (i == '(') {
                left++;
            }
            if (i == ')') {
                right++;
            }
            max1 = max(max1, left - right);
        }
        return max1;
    }
};