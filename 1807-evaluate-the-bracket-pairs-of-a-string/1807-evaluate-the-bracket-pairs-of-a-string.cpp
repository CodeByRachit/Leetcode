class Solution {
public:
    string evaluate(string s, vector<vector<string>>& k) {
        int n = s.length(), m = k.size();
        unordered_map<string, string> ump;
        ump.reserve(m);
        for(const auto& v : k) {
            ump[v[0]] = v[1];
        }
        string ans;
        ans.reserve(n);
        size_t posL = 0, prev = 0;
        while((posL = s.find('(', prev)) != string::npos) {
            ans += s.substr(prev, posL - prev);
            size_t posR = s.find(')', posL);
            string str = s.substr(posL + 1, posR - posL - 1);
            if(ump.contains(str)) {
                ans += ump[str];
            }
            else {
                ans += "?";
            }
            prev = posR + 1;
        }
        ans += s.substr(prev);
        return ans;
    }
};