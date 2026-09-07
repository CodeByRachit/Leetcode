using ll = long long;
class Solution {
public:
    const int M = 1e9+7;
    ll recur(string& s, int i, int prev, vector<vector<ll>>& dp){
        int n = s.size();
        if(i==n && prev!=-1) return 1LL;
        if(i==n) return 0;
        if(dp[i][prev+1]!=-1) return dp[i][prev+1];
        ll distinct;
        if(s[i]==prev+'a'){
            distinct = recur(s, i+1, prev, dp)%M;
            return dp[i][prev+1] = distinct;
        }
        distinct = (recur(s, i+1, s[i]-'a', dp)%M + recur(s, i+1, prev, dp)%M)%M;
        return dp[i][prev+1] = distinct;
    }
    int distinctSubseqII(string s) {
        int n = s.size();
        vector<vector<ll>> dp(n, vector<ll>(27,-1));
        return recur(s, 0, -1, dp);
    }
};