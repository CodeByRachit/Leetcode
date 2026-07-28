class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.length();
        if(n == 1) return s;
        vector<int> charCnt(26, 0);
        for(int i = 0; i < n; i++) {
            charCnt[s[i] - 'a']++;
        }
        int mid = n/2;
        int front = 0;
        int back = n - 1;
        vector<char> palindrome(n, 'a');
        for(int i = 0; i < 26; i++) {
            if(charCnt[i] % 2 == 0) {
                for(int j = 1; j <= charCnt[i]/2; j++) {
                    palindrome[front++] = i + 'a';
                    palindrome[back--] = i + 'a';
                }
            }
            else {
                palindrome[mid] = i + 'a';
                int cnt = charCnt[i] - 1;
                for(int j = 1; j <= charCnt[i]/2; j++) {
                    palindrome[front++] = i + 'a';
                    palindrome[back--] = i + 'a';
                }
            }
        }
        string res = "";
        for(int i = 0; i < n; i++) {
            res += palindrome[i];
        }
        return res;
    }
};