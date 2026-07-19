class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> last(26, -1);
        for (int i = 0; i < s.size(); i++)
            last[s[i] - 'a'] = i;
        vector<bool> isInStack(26, false);
        string st;
        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];
            if (isInStack[ch - 'a'])
                continue;
            while (!st.empty() && st.back() > ch && last[st.back() - 'a'] > i) {
                isInStack[st.back() - 'a'] = false;
                st.pop_back();
            }
            st.push_back(ch);
            isInStack[ch - 'a'] = true;
        }
        return st;
    }
};